#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

volatile sig_atomic_t sig_term = 0;
volatile sig_atomic_t begin;
volatile sig_atomic_t usr_sig_number;

void HandleSigUsr1(int signum)
{
    usr_sig_number = 1;
}

void HandleSigUsr2(int signum)
{
    usr_sig_number = 2;
}

void HandleSigTerm(int signum)
{
    ++sig_term;
}

int main()
{
    struct sigaction usr1_action;
    memset(&usr1_action, 0, sizeof(usr1_action));
    usr1_action.sa_handler = HandleSigUsr1;
    usr1_action.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &usr1_action, NULL);

    struct sigaction usr2_action;
    memset(&usr2_action, 0, sizeof(usr2_action));
    usr2_action.sa_handler = HandleSigUsr2;
    usr2_action.sa_flags = SA_RESTART;
    sigaction(SIGUSR2, &usr2_action, NULL);

    struct sigaction term_action;
    memset(&term_action, 0, sizeof(term_action));
    term_action.sa_handler = HandleSigTerm;
    term_action.sa_flags = SA_RESTART;
    sigaction(SIGTERM, &term_action, NULL);

    scanf("%d", &begin);

    printf("%d\n", getpid());
    fflush(stdout);

    while (sig_term == 0) {
        if (usr_sig_number == 1) {
            ++begin;

            printf("%d\n", begin);
            fflush(stdout);
        } else if (usr_sig_number == 2) {
            begin *= -1;

            printf("%d\n", begin);
            fflush(stdout);
        }

        pause();
    }

    return 0;
}
