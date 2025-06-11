#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include<string.h>
int main() {
    int a = open("input.txt", O_RDONLY);
    if (a == -1) {
        perror("Error opening file");
        return 1;
    }
    char keyword[100];
printf("\nEnter keyword to check:");
scanf("%s",keyword);
    int index = 0;
    char ch;
    int found = 0;

    while (read(a, &ch, 1) == 1) {
        if (ch == keyword[index]) {
            index++;
            if (index == strlen(keyword)) {
                found = 1;
                break;
            }
        } else {
            index = 0;  
        }
    }

    close(a);

    if (found) {
        printf("\nKeyword found in the file\n");
    } else {
        printf("\nKeyword not found in the file\n");
    }

    return 0;
}
