#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    char buffer[100];
    char input[100];

    pipe(fd);

    if (fork() == 0) { // Child process
        close(fd[0]);
        printf("Enter a message for the parent: ");
        fgets(input, sizeof(input), stdin);
        write(fd[1], input, strlen(input) + 1);
        close(fd[1]);
    } else { // Parent process
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        close(fd[0]);
        printf("Parent received: %s\n", buffer);
    }

    return 0;
}

