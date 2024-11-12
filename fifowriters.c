#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd;
    char *myfifo = "/tmp/myfifo";
    char input[100];

    mkfifo(myfifo, 0666);

    fd = open(myfifo, O_WRONLY);
    printf("Enter a message for the FIFO: ");
    fgets(input, sizeof(input), stdin);
    write(fd, input, strlen(input) + 1);
    close(fd);

    return 0;
}

