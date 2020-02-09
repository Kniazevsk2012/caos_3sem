#include <fcntl.h>
#include <inttypes.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

struct Item {
    int value;
    uint32_t next_pointer;
};

int main(int argc, char* argv[])
{
    char* file_name = argv[1];
    int file = open(file_name, O_RDONLY);

    if (file != -1) {
        struct stat st;
        fstat(file, &st);
        size_t file_size = st.st_size;
        if (file_size == 0) {
            return 0;
        }

        struct Item item;
        item.value = 0;
        item.next_pointer = -1;

        struct Item* data =
            mmap(NULL, file_size, PROT_READ, MAP_PRIVATE, file, 0);
        if (data == MAP_FAILED) {
            close(file);
            return 0;
        }
        item = data[0];
        while (item.next_pointer > 0) {
            printf("%d ", item.value);
            item = data[item.next_pointer / sizeof(item)];
        }
        printf("%d", item.value);
        munmap(data, file_size);
    }

    close(file);
}
