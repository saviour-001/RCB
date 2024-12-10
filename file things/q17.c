#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_LENGTH 100 

int main() {
    FILE *file;
    char filename[100];
    char lines[MAX_LINES][MAX_LENGTH];
    int lineCount = 0;
    char temp[MAX_LENGTH];

    printf("Enter the name of the file: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }

    while (fgets(lines[lineCount], MAX_LENGTH, file) != NULL) {
        lines[lineCount][strcspn(lines[lineCount], "\n")] = '\0';
        lineCount++;

        if (lineCount >= MAX_LINES) {
            printf("Error: Too many lines in the file.\n");
            fclose(file);
            exit(1);
        }
    }
    fclose(file);

    for (int i = 0; i < lineCount - 1; i++) {
        for (int j = i + 1; j < lineCount; j++) {
            if (strcmp(lines[i], lines[j]) > 0) {
                strcpy(temp, lines[i]);
                strcpy(lines[i], lines[j]);
                strcpy(lines[j], temp);
            }
        }
    }

    file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Cannot open file for writing.\n");
        exit(1);
    }

    for (int i = 0; i < lineCount; i++) {
        fprintf(file, "%s\n", lines[i]);
    }

    fclose(file);

    printf("The file contents have been sorted alphabetically.\n");

    return 0;
}
