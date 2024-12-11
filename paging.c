#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10

struct Page{
    int frameNumber; 
};

void printPageTable(struct Page pageTable[], int numPages) {
    printf("\nPage Table:\n");
    for (int i = 0; i < numPages; i++) {
        if (pageTable[i].frameNumber != -1) {
            printf("Page %d -> Frame %d\n", i, pageTable[i].frameNumber);
        }
    }
}

int main() {
    int logicalAddress, pageNumber, offset, frameNumber, numPages;
    int pageSize, memorySize;
    struct Page pageTable[MAX_PAGES];

    printf("Enter the total memory size (in number of words): ");
    scanf("%d", &memorySize);

    printf("Enter the page size (in number of words): ");
    scanf("%d", &pageSize);
    printf("enter number of pages to map ");
    scanf("%d",&numPages);
    int max = memorySize / pageSize;
    if (numPages > max) {
        printf("Number of pages exceeds maximum limit (%d). Exiting.\n", max);
        return 1;
    }

    printf("Enter the frame mappings for each page (-1 if not mapped):\n");
    for (int i = 0; i < numPages; i++) {
        printf("Page %d -> Frame: ", i);
        scanf("%d", &frameNumber);
        pageTable[i].frameNumber = frameNumber;
    }

    while (1) {
        printf("\nEnter a logical address (-1 to exit): ");
        scanf("%d", &logicalAddress);

        if (logicalAddress == -1) {
            break;
        }

        pageNumber = logicalAddress / pageSize;
        offset = logicalAddress % pageSize;

        if (pageNumber < 0 || pageNumber >= numPages || offset < 0 || offset >= pageSize ||
            pageTable[pageNumber].frameNumber == -1) {
            printf("Invalid logical address or page not mapped to a frame.\n");
            continue;
        }

        frameNumber = pageTable[pageNumber].frameNumber;
        int physicalAddress = frameNumber * pageSize + offset;
        printf("Logical address %d maps to physical address %d\n", logicalAddress, physicalAddress);
    }

    printPageTable(pageTable, numPages);

    return 0;
}