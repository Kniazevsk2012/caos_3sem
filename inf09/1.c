#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    long N = strtol(argv[1], NULL, 10);
    for (long i = 0; i < N; ++i) {
        pid_t pid = fork();
        if (pid == 0) {
            if (i == N - 1) {
                printf("%lu\n", i + 1);
            } else if (i < N - 1) {
                printf("%lu ", i + 1);
            }
            exit(0);
        }
        int status;
        waitpid(pid, &status, 0);
    }
    return 0;
}
