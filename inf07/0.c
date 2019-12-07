#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
    int exit_code = 0;
    int file = open(argv[1], O_RDONLY);

    if (file == -1) {
        exit_code = 1;
        goto finish;
    }

    int out_1_file = open(argv[2], O_WRONLY | O_CREAT, 0640);

    if (out_1_file == -1) {
        exit_code = 2;
        goto finish;
    }

    int out_2_file = open(argv[3], O_WRONLY | O_CREAT, 0640);

    if (out_2_file == -1) {
        exit_code = 2;
        goto finish;
    }

    ssize_t write_bytes = 0;
    char byte;

    while (read(file, &byte, sizeof(byte))) {
        if ('0' <= byte && byte <= '9') {
            write_bytes = write(out_1_file, &byte, sizeof(byte));
        } else {
            write_bytes = write(out_2_file, &byte, sizeof(byte));
        }

        if (write_bytes <= 0) {
            exit_code = 3;
            goto finish;
        }
    }

finish:
    close(file);
    close(out_1_file);
    close(out_2_file);
    return exit_code;
}
