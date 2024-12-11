#include <stdio.h>
#include <stdlib.h>

#define MAX_PAGES 10
#define FRAME_COUNT 10

struct PageTableEntry {
    int frameNumber; 
};

struct PageTable {
    struct PageTableEntry entries[MAX_PAGES];
};

void initializePageTable(struct PageTable *pt) {
    for (int i = 0; i < MAX_PAGES; i++) {
        pt->entries[i].frameNumber = -1;
    }

}

void printPageTable(struct PageTable *pt) {
    printf("\nPage Table:\n");
    for (int i = 0; i < MAX_PAGES; i++) {
        if (pt->entries[i].frameNumber != -1) {
            printf("Page %d -> Frame %d\n", i, pt->entries[i].frameNumber);
        }
    }
}

int main() {
    int logicalAddress, pageNumber, offset, frameNumber, numPages;
    int pageSize, memorySize;
    struct PageTable pageTable;

    printf("Enter the page size (in number of words): ");
    scanf("%d", &pageSize);
    printf("Enter the total memory size (in number of words): ");
    scanf("%d", &memorySize);

    initializePageTable(&pageTable);

    printf("Enter the number of pages to map (max %d): ", MAX_PAGES);
    scanf("%d", &numPages);

    if (numPages > MAX_PAGES || numPages <= 0) {
        printf("Invalid number of pages. Exiting.\n");

        return 1;
    }

    for (int i = 0; i < numPages; i++) {
        printf("Enter frame number for Page %d (-1 if not mapped): ", i);
        scanf("%d", &frameNumber);
        pageTable.entries[i].frameNumber = frameNumber;

    }

    while (1) {
        printf("\nEnter a logical address (-1 to exit): ");
        scanf("%d", &logicalAddress);

        if (logicalAddress == -1) {

            break;
        }

        pageNumber = logicalAddress / pageSize;
        offset = logicalAddress % pageSize;

        printf("Logical address: %d, Page number: %d, Offset: %d\n", logicalAddress, pageNumber, offset);

        if (pageNumber < 0 || pageNumber >= MAX_PAGES || offset < 0 || offset >= pageSize ||
            pageTable.entries[pageNumber].frameNumber == -1) {
            printf("Invalid logical address or page not mapped to a frame.\n");
 
            continue;
        }

        frameNumber = pageTable.entries[pageNumber].frameNumber;
        int physicalAddress = frameNumber * pageSize + offset;
        printf("Logical address %d maps to physical address %d\n",
               logicalAddress, physicalAddress);
        
    }

    printPageTable(&pageTable);
    return 0;
}    