#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork failed");
        return 1;
    }
    else if (pid == 0)
    {
        // Child process
        printf("Hello from Child Process! (PID: %d)\n", getpid());
    }
    else
    {
        // Parent process
        printf("Hello from Parent Process! (PID: %d)\n", getpid());
    }

    return 0;
}