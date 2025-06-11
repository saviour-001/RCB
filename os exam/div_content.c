#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    int fd = open("file.txt", O_RDONLY);
    int fd1 = open("part1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    int fd2 = open("part2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char c;
    int line = 1;
    while (read(fd, &c, 1))
    {
        if (line % 2)
            write(fd1, &c, 1);
        else
            write(fd2, &c, 1);
        if (c == '\n')
            line++;
    }
    close(fd);
    close(fd1);
    close(fd2);
    printf("File split into part1.txt and part2.txt\n");
    return 0;
}