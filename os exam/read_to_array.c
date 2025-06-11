#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

int main() {
    int fd = open("input.txt", O_RDONLY);
    if (fd == -1) {
        // write(2,"Error opening file",18);
        perror("Error opening file");
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    char buffer[MAX_LINE_LENGTH];
    int line_count = 0;
    int index = 0;
    char ch;

    while (read(fd, &ch, 1) > 0) {
        if (index < MAX_LINE_LENGTH - 1) {
            buffer[index++] = ch;
        }
        if (ch == '\n' || index == MAX_LINE_LENGTH - 1) {
            buffer[index] = '\0';
            snprintf(lines[line_count], MAX_LINE_LENGTH, "%s", buffer);
            line_count++;
            index = 0;
            if (line_count >= MAX_LINES) {
                break;
            }
        }
    }
    if (index > 0) {
        buffer[index] = '\0';
        snprintf(lines[line_count], MAX_LINE_LENGTH, "%s", buffer);
        line_count++;
    }

    close(fd);

   for (int i = 0; i < line_count; i++) {
        printf("%s\n", lines[i]); 
   }
     close(fd);
    return 0;
}
