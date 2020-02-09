#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int main()
{
    char file_name[PATH_MAX];
    while (fgets(file_name, PATH_MAX, stdin)) {
        char* const end_of_line = memchr(file_name, '\n', sizeof(file_name));
        if (end_of_line) {
            *end_of_line = '\0';
        }
        int fd = open(file_name, O_RDONLY);
        if (fd == -1) {
            continue;
        }
        struct stat file_stat;
        if (lstat(file_name, &file_stat) != -1) {
            if (S_ISREG(file_stat.st_mode)) {
                char link_name[PATH_MAX] = {
                    'l', 'i', 'n', 'k', '_', 't', 'o', '_'};
                for (int i = 0; i < PATH_MAX; i++) {
                    link_name[i + 8] = file_name[i];
                    if (file_name[i] == '\0') {
                        break;
                    }
                }
                close(fd);
                continue;
            }
            if (S_ISLNK(file_stat.st_mode)) {
                char link_name[PATH_MAX];
                if (realpath(file_name, link_name)) {
                    printf("%s\n", link_name);
                }
                close(fd);
                continue;
            }
        }
        close(fd);
    }
}
