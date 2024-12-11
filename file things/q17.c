#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

int main() {
    char filename[100];
    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int lineCount = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        return 1;
    }

    while (fgets(lines[lineCount], sizeof(lines[lineCount]), file) != NULL) {
        lineCount++;
        if (lineCount >= MAX_LINES) {
            printf("Warning: Maximum number of lines exceeded\n");
            break;
        }
    }

    fclose(file);

    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = 0; j < lineCount - i - 1; j++) {
            if (strcmp(lines[j], lines[j + 1]) > 0) {
                char temp[MAX_LINE_LENGTH];
                strcpy(temp, lines[j]);
                strcpy(lines[j], lines[j + 1]);
                strcpy(lines[j + 1], temp);
            }
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open the file for writing\n");
        return 1;
    }

    for (int i = 0; i < lineCount; i++) {
        fputs(lines[i], file);
    }

    fclose(file);

    printf("File sorted successfully.\n");

    return 0;
}