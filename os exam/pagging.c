#include <stdio.h>

int main() {
    int memSize, pageSize;
    int numPages, numFrames;

    printf("Enter the total memory size (in bytes): ");
    scanf("%d", &memSize);

    printf("Enter the page size (in bytes): ");
    scanf("%d", &pageSize);

    numPages = memSize / pageSize;
    numFrames = numPages;

    int pageTable[numPages];
    int usedFrames[numFrames];  // to track duplicate frame use

    for (int i = 0; i < numFrames; i++) {
        usedFrames[i] = 0;
    }
    printf("\nPage Table\n");
    printf("\nEnter the frame number for each page (0 to %d):\n", numFrames - 1);
    for (int i = 0; i < numPages; i++) {
        int frame;
        printf("Page %d: ", i);
        scanf("%d", &frame);

        // Validate frame range
        if (frame < 0 || frame >= numFrames) {
            printf("Error: Frame number %d is out of valid range (0 to %d).\n", frame, numFrames - 1);
            return 1;
        }

        // Check for duplicate
        if (usedFrames[frame]) {
            printf("Error: Frame number %d already assigned to another page.\n", frame);
            return 1;
        }

        usedFrames[frame] = 1; // mark as used
        pageTable[i] = frame;
    }

    int logicalAddr;
    printf("\nEnter the logical address (in decimal): ");
    scanf("%d", &logicalAddr);

    int pageNum = logicalAddr / pageSize;
    int offset = logicalAddr % pageSize;

    if (pageNum >= numPages) {
        printf("Invalid page number. Logical address is out of range.\n");
        return 1;
    }

    int frameNum = pageTable[pageNum];
    int physicalAddr = frameNum * pageSize + offset;

    // Clean output format
    printf("\nLogical Address: %d\n", logicalAddr);
    printf("Page Number: %d\n", pageNum);
    printf("Offset: %d\n", offset);
    printf("Mapped to Frame Number: %d\n", frameNum);
    printf("Physical Address: %d * %d + %d = %d\n", frameNum, pageSize, offset, physicalAddr);

    return 0;
}
