#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    char ch;
    int inWord = 0, wordCount = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || ch == '\n' || ch == '\t') {
            if (inWord) {
                inWord = 0;
                wordCount++;
            }
        } else {
            inWord = 1;
        }
    }

    if (inWord) {
        wordCount++;
    }

    fclose(file);

    printf("Number of words in the file: %d\n", wordCount);

    return 0;
}
