#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

int main() {
    char filename[100], keyword[100];

    // Prompt for the filename and keyword
    printf("Enter the file name: ");
    scanf("%s", filename);
    printf("Enter the keyword to search for: ");
    scanf("%s", keyword);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;

    // Read each line and check for the keyword
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, keyword) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (found) {
        printf("The keyword '%s' is present in the file.\n", keyword);
    } else {
        printf("The keyword '%s' is not present in the file.\n", keyword);
    }

    return 0;
}
