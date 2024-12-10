#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100], target;
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the character to count: ");
    scanf(" %c", &target);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    char ch;
    int count = 0;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == target) {
            count++;
        }
    }

    fclose(file);

    printf("The character '%c' occurs %d times in the file.\n", target, count);

    return 0;
}
