#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int fd = open("file.txt", O_RDWR);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }

    char ch;
    char tab = '\t';

    int pos = 0; // Track the current position

    while (read(fd, &ch, 1) == 1)
    {
        if (ch == '\n')
        {
            lseek(fd, pos, SEEK_SET);     // Move to the exact position of '\n'
            write(fd, &tab, 1);           // Replace with a tab
        }
        pos = lseek(fd, 0, SEEK_CUR); // Keep updating the current position
    }

    close(fd);
    return 0;
}