#include <fcntl.h>
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
    ssize_t read_bytes = 0;
    ssize_t write_1 = 0;
    ssize_t write_2 = 0;
    char buffer_read[256];
    char buffer_write_1[256];
    char buffer_write_2[256];

    read_bytes = read(file, buffer_read, 256);
    while (read_bytes) {
        write_1 = 0;
        write_2 = 0;

        for (ssize_t i = 0; i < read_bytes; ++i) {
            if ('0' <= buffer_read[i] && buffer_read[i] <= '9') {
                buffer_write_1[write_1] = buffer_read[i];
                ++write_1;
            } else {
                buffer_write_2[write_2] = buffer_read[i];
                ++write_2;
            }
        }

        write_bytes = write(out_1_file, buffer_write_1, write_1);
        if (write_bytes == -1) {
            exit_code = 3;
            goto finish;
        }

        write_bytes = write(out_2_file, buffer_write_2, write_2);
        if (write_bytes == -1) {
            exit_code = 3;
            goto finish;
        }

        read_bytes = read(file, buffer_read, 256);
    }

finish:
    if (file != -1) {
        close(file);
    }

    if (out_1_file != -1) {
        close(out_1_file);
    }

    if (out_2_file != -1) {
        close(out_2_file);
    }

    return exit_code;
}
