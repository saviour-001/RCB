#include <stdio.h>
#include <stdlib.h>

#define PAGE_SIZE 4

int main() {
    int numberOfPages;

    printf("Enter the number of pages: ");
    scanf("%d", &numberOfPages);

    int pageTable[numberOfPages];

    for (int i = 0; i < numberOfPages; i++) {
        printf("Enter frame number for page %d: ", i);
        scanf("%d", &pageTable[i]);
    }

    int logicalAddress;

    printf("Enter a logical address: ");
    scanf("%d", &logicalAddress);

    int pageNumber = logicalAddress / PAGE_SIZE;
    int offset = logicalAddress % PAGE_SIZE;

    if (pageNumber >= numberOfPages) {
        printf("Invalid logical address!\n");
        return 1;
    }

    int frameNumber = pageTable[pageNumber];
    int physicalAddress = frameNumber * PAGE_SIZE + offset;

    printf("\nLogical Address: %d\n", logicalAddress);
    printf("Page Number: %d\n", pageNumber);
    printf("Frame Number: %d\n", frameNumber);
    printf("Offset: %d\n", offset);
    printf("Physical Address: %d\n", physicalAddress);

    return 0;
}
