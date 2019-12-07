#include <inttypes.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

int main()
{
    ssize_t size = 0;
    char name[PATH_MAX];
    while (fgets(name, PATH_MAX, stdin) != NULL) {
        char* const end_of_line = memchr(name, '\n', sizeof(name));
        if (end_of_line) {
            *end_of_line = '\0';
        }
        struct stat status;
        if (lstat(name, &status) != -1) {
            if (S_ISREG(status.st_mode)) {
                size += status.st_size;
            }
        }
    }
    printf("%lu", size);
}
