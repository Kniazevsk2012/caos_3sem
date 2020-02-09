#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char word[4096];
    int counter = 0;
    int status;
    do {
        pid_t pid = fork();
        if (pid == 0) {
            if (scanf("%s", word) == EOF) {
                return 0;
            }
            return 1;
        } else {
            waitpid(pid, &status, 0);
            counter = counter + WEXITSTATUS(status);
        }
    } while (status);
    printf("%d", counter);
    return 0;
}
