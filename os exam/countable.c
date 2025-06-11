#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
int main() {
    int character = 0, words = 0, lines = 0;
    char ch, last_char = '\0';
    int inword = 0;
    int x = open("int.txt", O_RDONLY);
    if (x == -1) {
        perror("Error opening file");
        return 1;
    }
    while (read(x, &ch, 1) == 1) {
        character++;  
        if (ch == '\n') 
            lines++;
        if (isspace(ch)) {
            if (inword) {
                words++;
                inword = 0;
            }
        }  
        else {
            inword = 1;
        }
        last_char = ch;
    }
    if (inword) 
        words++;
    if (character > 0 && last_char != '\n') 
        lines++; 
    printf("Number of characters: %d\n", character);
    printf("Number of words: %d\n", words);
    printf("Number of lines: %d\n", lines);
    close(x);
    return 0;
}
