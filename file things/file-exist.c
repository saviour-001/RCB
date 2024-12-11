#include <stdio.h>
#include <stdlib.h>

int main() {
    char filename[100];
    printf("Enter the file name: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        fclose(file);
        file = fopen(filename, "w");
        if (file != NULL) {
            printf("File exists. The file length has been set to zero.\n");
            fclose(file);
        } else {
            printf("Error: Unable to truncate the file.\n");
            exit(1);
        }
    } else {
        printf("File does not exist.\n");
    }

    return 0;
}
