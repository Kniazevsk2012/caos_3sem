#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char python_expression[8192];

    fgets(python_expression, 8192, stdin);

    char program_text[8192];
    char* break_search = strchr(python_expression, '\n');

    if (break_search != NULL) {
        *break_search = '\0';
    }

    if (strnlen(python_expression, 8192) == 0) {
        return 0;
    }

    snprintf(program_text, 8192, "value = %s; print(value)", python_expression);

    execlp("python3", "python3", "-c", program_text, NULL);

    perror("exec fail");

    return 1;
}
