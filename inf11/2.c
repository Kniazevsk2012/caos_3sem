#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

volatile sig_atomic_t signal_handled = 0;

void HandleSigAlarm(int signum)
{
    signal_handled = 1;
}

void HandleSigChild(int signum)
{
    signal_handled = 2;
}

int main(int argc, char* argv[])
{
    struct sigaction sig_alarm_action;
    memset(&sig_alarm_action, 0, sizeof(sig_alarm_action));
    sig_alarm_action.sa_handler = HandleSigAlarm;
    sig_alarm_action.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sig_alarm_action, NULL);

    struct sigaction sig_child_action;
    memset(&sig_child_action, 0, sizeof(sig_child_action));
    sig_child_action.sa_handler = HandleSigChild;
    sig_child_action.sa_flags = SA_RESTART;
    sigaction(SIGCHLD, &sig_child_action, NULL);

    pid_t pid = fork();
    if (pid == 0) {
        execvp(argv[2], argv + 2);
        perror("exec fail");
        exit(1);
    }

    long time = strtol(argv[1], NULL, 10);
    alarm(time);

    while (!signal_handled) {
        pause();
    }

    int status;
    if (signal_handled == 1) {
        kill(pid, SIGTERM);
        waitpid(pid, &status, 0);
        printf("%s\n", "timeout");
        return 2;
    } else {
        waitpid(pid, &status, 0);
        if (WIFSIGNALED(status)) {
            printf("%s\n", "signaled");
            return 1;
        } else {
            printf("%s\n", "ok");
            return 0;
        }
    }
}
