#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    char* file_name = argv[1];
    char* pattern = argv[2];
    int fd = open(file_name, O_RDONLY);

    if (fd != -1) {
        struct stat st;
        fstat(fd, &st);
        char* content = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
        if (content == MAP_FAILED) {
            close(fd);
            return 0;
        }

        char* entry = content;
        while (entry = strstr(entry, pattern)) {
            size_t diff = entry - content;
            printf("%lu ", diff);
            size_t remaining_file = st.st_size - diff;
            ++entry;
        }
        printf("\n");
        munmap(content, st.st_size);
    }

    close(fd);
}
