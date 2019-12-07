#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    for (int i = 1; 1; ++i) {
        int pid = fork();
        if (pid == -1) {
            printf("%d\n", i);
            return 0;
        }
        if (pid > 0) {
            int status;
            waitpid(pid, &status, 0);
            break;
        }
    }
    return 0;
}
