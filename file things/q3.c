#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_LINE_LENGTH 256

int main() {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    char *lines[MAX_LINES];
    int lineCount = 0;
    char buffer[MAX_LINE_LENGTH];

    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (lineCount >= MAX_LINES) {
            printf("Warning: Maximum number of lines exceeded\n");
            break;
        }
        lines[lineCount] = (char *)malloc(strlen(buffer) + 1);
        strcpy(lines[lineCount], buffer);
        lineCount++;
    }

    fclose(file);

    printf("The lines in the file are:\n");
    for (int i = 0; i < lineCount; i++) {
        printf("%s", lines[i]);
        free(lines[i]);
    }

    return 0;
}
