#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main() {
    int x;
    int y = open("input.txt", O_RDONLY);
    if (y == -1) {
        write(2, "Error opening file\n", 19);
        return 1;
    }
    int a = open("even.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (a == -1) {
        write(2, "Error opening even file\n", 24);
        close(y);
        return 1;
    }
    int b = open("odd.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (b == -1) {
        write(2, "Error opening odd file\n", 23);
        close(y);
        close(a);
        return 1;
    }
    char ch, num_buffer[20];
    int index = 0;
    while (read(y, &ch, 1) == 1) {
        if (ch >= '0' && ch <= '9') {
            num_buffer[index++] = ch;
        } else if (index > 0) {
            num_buffer[index] = '\0';
            x = atoi(num_buffer);
            char output[20];
            int len = snprintf(output, sizeof(output), "%d ", x);
            if (x % 2 == 0) {
                write(a, output, len);
            } else {
                write(b, output, len);
            }
            index = 0;
        }
    }
if (index > 0) {
        num_buffer[index] = '\0';
        x = atoi(num_buffer);
        char output[20];
        int len = snprintf(output, sizeof(output), "%d ", x);
        if (x % 2 == 0) {
            write(a, output, len);
        } else {
            write(b, output, len);
        }
    }
    close(y);
    close(a);
    close(b);
    return 0;
}
