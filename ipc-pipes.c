#include <stdio.h>
#include <unistd.h>

int main() {
    int fd[2];
    char write_msg[] = "Hello through the pipe!";
    char read_msg[20];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    if (fork() == 0) {
        close(fd[0]);
        write(fd[1], write_msg, sizeof(write_msg));
        close(fd[1]);
    } else {
        close(fd[1]);
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Parent read: %s\n", read_msg);
        close(fd[0]);
    }

    return 0;
}