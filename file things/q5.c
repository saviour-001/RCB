#include <stdio.h>
#include <stdlib.h>

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
    int lineCount = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            lineCount++;
        }
    }
    if (ch != '\n' && lineCount > 0) {
        lineCount++;
    }

    fclose(file);

    printf("Number of lines in the file: %d\n", lineCount);

    return 0;
}
