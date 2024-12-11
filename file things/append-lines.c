#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100], line[256];
    int n;

    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    printf("Enter the number of lines to append: ");
    scanf("%d", &n);
    getchar();

    printf("Enter the lines:\n");
    for (int i = 0; i < n; i++) {
        fgets(line, sizeof(line), stdin);
        fputs(line, file);
    }

    fclose(file);

    printf("Lines appended successfully.\n");

    return 0;
}
