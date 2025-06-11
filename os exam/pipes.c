#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int pipefd[2]; // pipefd[0] - read end, pipefd[1] - write end
    pid_t pid;
    char write_msg[] = "Hello from parent to child via pipe!";
    char read_msg[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        return 1;
    }

    // Fork a child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]); // Close unused read end
        write(pipefd[1], write_msg, strlen(write_msg) + 1); // Write to pipe
        close(pipefd[1]); // Close write end after writing
    } else {
        // Child process
        close(pipefd[1]); // Close unused write end
        read(pipefd[0], read_msg, sizeof(read_msg)); // Read from pipe
        printf("Child received: %s\n", read_msg);
        close(pipefd[0]); // Close read end
    }   

    return 0;
}
