#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

volatile sig_atomic_t sig_int_counter = 0;
volatile sig_atomic_t sig_term_counter = 0;

void Handler(int signum)
{
    if (signum == SIGINT) {
        ++sig_int_counter;
    }

    if (signum == SIGTERM) {
        ++sig_term_counter;
    }
}

int main()
{
    struct sigaction sig_action;
    memset(&sig_action, 0, sizeof(sig_action));
    sig_action.sa_handler = Handler;
    sig_action.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sig_action, NULL);
    sigaction(SIGTERM, &sig_action, NULL);

    printf("%d\n", getpid());
    fflush(stdout);

    while (sig_term_counter == 0) {
        pause();
    }

    printf("%d\n", sig_int_counter);

    return 0;
}
