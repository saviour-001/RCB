#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
    struct stat file_stat;

    // Check file information using stat()
    if (stat("input.txt", &file_stat) == -1)
    {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    // Display file information
    printf("File size: %ld bytes\n", file_stat.st_size);
    printf("Number of links: %ld\n", file_stat.st_nlink);
    printf("File inode: %ld\n", file_stat.st_ino);

    return 0;
}