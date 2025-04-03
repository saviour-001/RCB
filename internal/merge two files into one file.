#include <stdio.h>
#include <stdlib.h>

int main() {
    char file1[100], file2[100], outputFile[100];

    printf("Enter the name of the first file: ");
    scanf("%s", file1);
    printf("Enter the name of the second file: ");
    scanf("%s", file2);
    printf("Enter the name of the output file: ");
    scanf("%s", outputFile);

    FILE *source1 = fopen(file1, "r");
    if (source1 == NULL) {
        printf("Error: Unable to open file %s\n", file1);
        exit(1);
    }

    FILE *source2 = fopen(file2, "r");
    if (source2 == NULL) {
        printf("Error: Unable to open file %s\n", file2);
        fclose(source1);
        exit(1);
    }

    FILE *destination = fopen(outputFile, "w");
    if (destination == NULL) {
        printf("Error: Unable to create output file %s\n", outputFile);
        fclose(source1);
        fclose(source2);
        exit(1);
    }

    int ch;
    while ((ch = fgetc(source1)) != EOF) {
        fputc(ch, destination);
    }

    while ((ch = fgetc(source2)) != EOF) {
        fputc(ch, destination);
    }

    printf("Files merged successfully into %s\n", outputFile);

    fclose(source1);
    fclose(source2);
    fclose(destination);

    return 0;
}
