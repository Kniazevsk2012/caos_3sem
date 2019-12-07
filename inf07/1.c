#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

struct Node {
    int value;
    uint32_t next_pointer;
};

int main(int args, char* argv[])
{
    int in_file = open(argv[1], O_RDONLY);
    int exit_code = 0;

    struct Node node;
    node.value = 0;
    node.next_pointer = -1;

    if (in_file < 0) {
        exit_code = 1;
        goto finish;
    }

    ssize_t read_bytes = read(in_file, &node, sizeof(node));

    if (read_bytes <= 0) {
        exit_code = 0;
        goto finish;
    }

    while (node.next_pointer > 0) {
        printf("%d\n", node.value);
        lseek(in_file, node.next_pointer, SEEK_SET);

        read(in_file, &node, sizeof(node));
    }

    printf("%d", node.value);

finish:
    close(in_file);
    return exit_code;
}
