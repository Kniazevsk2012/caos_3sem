#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    char program[2048];
    char c_expression[2048];
    fgets(c_expression, sizeof(c_expression), stdin);
    if (strnlen(c_expression, sizeof(c_expression)) == 0) {
        return 0;
    }

    char* break_search = strchr(c_expression, '\n');
    if (break_search != NULL) {
        *break_search = '\0';
    }

    int f = open("file.c", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    snprintf(
        program,
        sizeof(program),
        "#include <stdio.h>\n int main() {"
        "int value = (%s);"
        "printf(\"%%d\", "
        "value); return 0; }",
        c_expression);
    write(f, program, strnlen(program, sizeof(program)));
    close(f);

    int status;

    pid_t pid = fork();
    if (pid != 0) {
        waitpid(pid, &status, 0);
    } else {
        execlp("gcc", "gcc", "-o", "file", "file.c", NULL);
        exit(0);
    }

    pid = fork();

    if (pid != 0) {
        waitpid(pid, &status, 0);
    } else {
        execlp("./file", "./file", NULL);
        exit(0);
    }

    remove("file");
    remove("file.c");
    return 0;
}
