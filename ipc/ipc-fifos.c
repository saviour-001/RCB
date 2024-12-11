#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
    int fd;
    char *fifo_path = "/tmp/my_fifo";
    char write_msg[] = "Hello through FIFO!";
    char read_msg[20];

    mkfifo(fifo_path, 0666);

    if (fork() == 0) {
        fd = open(fifo_path, O_WRONLY);
        write(fd, write_msg, sizeof(write_msg));
        close(fd);
    } else {
        fd = open(fifo_path, O_RDONLY);
        read(fd, read_msg, sizeof(read_msg));
        printf("Parent read: %s\n", read_msg);
        close(fd);
        unlink(fifo_path);
    }

    return 0;
}