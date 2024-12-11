#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LINE_LENGTH 256

int main() {
    char filename[100];
    char *lines[MAX_LINES];
    int lineCount = 0;

    printf("Enter the file name: ");
    scanf("%s", filename);
    
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        lines[lineCount] = (char *)malloc(strlen(buffer) + 1);
        if (lines[lineCount] == NULL) {
            printf("Memory allocation failed\n");
            fclose(file);
            exit(1);
        }
        strcpy(lines[lineCount], buffer);
        lineCount++;

        if (lineCount >= MAX_LINES) {
            printf("Warning: Maximum number of lines exceeded\n");
            break;
        }
    }

    fclose(file);

    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = i + 1; j < lineCount; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                char *temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Unable to open the file for writing\n");
        exit(1);
    }

    for (int i = 0; i < lineCount; i++) {
        fputs(lines[i], file);
        free(lines[i]);  
    }

    fclose(file);

    printf("File sorted successfully.\n");

    return 0;
}
