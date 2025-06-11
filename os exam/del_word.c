#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 1024
char WORD[100];

int main() {
    int fd = open("input.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        return 1;
    }

    char buf[BUF_SIZE];
    int n, write_pos = 0;

    printf("Enter word to delete:");
    scanf("%s",WORD);
    while ((n = read(fd, buf, sizeof(buf))) > 0) {
        int i = 0, j = 0;
        while (i < n) {
            if (strncmp(&buf[i], WORD, strlen(WORD)) == 0) {
                i += strlen(WORD);  // Skip "delete"
            } else {
                buf[j++] = buf[i++];  // Keep other characters
            }
        }

        lseek(fd, write_pos, SEEK_SET);
        write(fd, buf, j);
        write_pos += j;
    }

    ftruncate(fd, write_pos);
    printf("Word deleted");
    close(fd);
    return 0;
}
