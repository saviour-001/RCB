#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buffer[100];

    fd = open(myfifo, O_RDONLY);
    read(fd, buffer, sizeof(buffer));
    close(fd);

    printf("Received from FIFO: %s\n", buffer);

    return 0;
}

