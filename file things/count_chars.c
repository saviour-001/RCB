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
    int charCount = 0;

    while ((ch = fgetc(file)) != EOF) {
        charCount++;
    }

    fclose(file);

    printf("Number of characters in the file: %d\n", charCount);

    return 0;
}