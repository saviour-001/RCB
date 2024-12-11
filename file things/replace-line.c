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

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        printf("Error: Unable to create temporary file\n");
        fclose(file);
        exit(1);
    }

    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            fputc('\t', tempFile);
        } else {
            fputc(ch, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(filename);
    rename("temp.txt", filename);

    printf("All newline characters have been replaced with tabs in the file.\n");

    return 0;
}
