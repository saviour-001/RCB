#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char filename[100], word[100];
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the word to delete: ");
    scanf("%s", word);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Unable to create temporary file\n");
        fclose(file);
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    char *pos;
    int len = strlen(word);

    while (fgets(line, sizeof(line), file) != NULL) {
        while ((pos = strstr(line, word)) != NULL) {
            memmove(pos, pos + len, strlen(pos + len) + 1);
        }
        fputs(line, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);

    printf("Word '%s' deleted from the file successfully.\n", word);

    return 0;
}
