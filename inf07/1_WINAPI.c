#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <windows.h>

struct Node {
    int value;
    uint32_t next_pointer;
};

int main(int args, char* argv[])
{
    DWORD dwShareMode = 0;
    HANDLE in_file = CreateFileA(
        argv[1],
        GENERIC_READ,
        dwShareMode,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_READONLY,
        NULL);
    int exit_code = 0;

    struct Node node;
    node.value = 0;
    node.next_pointer = -1;

    if (in_file < 0) {
        exit_code = 1;
        goto finish;
    }

    DWORD read_bytes;
    ReadFile(in_file, &node, sizeof(node), &read_bytes, NULL);

    if (!read_bytes) {
        exit_code = 0;
        goto finish;
    }

    while (node.next_pointer > 0) {
        printf("%d\n", node.value);
        SetFilePointer(in_file, node.next_pointer, NULL, FILE_BEGIN);

        ReadFile(in_file, &node, sizeof(node), &read_bytes, NULL);
    }

    printf("%d", node.value);

finish:
    DeleteFileA(argv[1]);
    return exit_code;
}
