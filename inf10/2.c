#include <fcntl.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

volatile bool sig_pipe_handled = false;

void HandleSigPipe(int signum)
{
    sig_pipe_handled = true;
}

int main(int argc, char* argv[])
{
    struct sigaction action_pipe;
    memset(&action_pipe, 0, sizeof(action_pipe));
    action_pipe.sa_handler = HandleSigPipe;
    action_pipe.sa_flags = SA_RESTART;
    sigaction(SIGPIPE, &action_pipe, NULL);

    long max_num = strtol(argv[2], NULL, 10);
    char* fifo_name = argv[1];

    mkfifo(fifo_name, 0642);

    pid_t pid;
    scanf("%d", &pid);
    kill(pid, SIGHUP);

    int fifo = open(fifo_name, O_WRONLY);
    FILE* file = fdopen(fifo, "w");
    int counter = 0;
    while (counter <= max_num && !sig_pipe_handled) {
        fprintf(file, "%d ", counter);
        ++counter;
    }
    printf("%d", counter);
    fflush(stdout);
    fclose(file);
    return 0;
}
