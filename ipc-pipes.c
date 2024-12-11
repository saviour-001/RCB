#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h> // For wait()

int main() {
    int pipefd[2]; // Array to hold pipe file descriptors
    pid_t pid;
    char writeMsg[] = "Hello from parent!";
    char readMsg[100];

    // Create the pipe
    if (pipe(pipefd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Fork the process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid > 0) {
        // Parent process
        close(pipefd[0]); // Close unused read end of the pipe
        printf("Parent: Writing message to pipe...\n");
        if (write(pipefd[1], writeMsg, strlen(writeMsg) + 1) == -1) {
            perror("Write failed");
        }
        close(pipefd[1]); // Close write end after writing
        wait(NULL); // Wait for the child to finish
    } else {
        // Child process
        close(pipefd[1]); // Close unused write end of the pipe
        ssize_t bytesRead = read(pipefd[0], readMsg, sizeof(readMsg));
        if (bytesRead == -1) {
            perror("Read failed");
        } else {
            printf("Child: Read message from pipe: '%s'\n", readMsg);
        }
        close(pipefd[0]); // Close read end after reading
    }

    return 0;
}    