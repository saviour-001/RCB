#include <stdio.h>
#include <stdlib.h>

#define MAX_SEGMENTS 10

struct SegmentTableEntry {
    int base;
    int limit; 
};

struct SegmentTable {
    struct SegmentTableEntry entries[MAX_SEGMENTS];
};

void initializeSegmentTable(struct SegmentTable *st) {
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        st->entries[i].base = -1;
        st->entries[i].limit = 0;
    }

}

void printSegmentTable(struct SegmentTable *st) {
    printf("\nSegment Table:\n");
    for (int i = 0; i < MAX_SEGMENTS; i++) {
        if (st->entries[i].base != -1) {
            printf("Segment %d -> Base: %d, Limit: %d\n", 
                   i, st->entries[i].base, st->entries[i].limit);
        }
    }
}

int main() {
    int logicalAddress, segmentNumber, offset, numSegments;
    struct SegmentTable segmentTable;

    int memorySize;
    printf("Enter the total memory size (in number of words): ");
    scanf("%d", &memorySize);

    initializeSegmentTable(&segmentTable);

    printf("Enter the number of segments to map (max %d): ", MAX_SEGMENTS);
    scanf("%d", &numSegments);

    if (numSegments > MAX_SEGMENTS || numSegments <= 0) {
        printf("Invalid number of segments. Exiting.\n");
        return 1;
    }

    for (int i = 0; i < numSegments; i++) {
        printf("Enter base address and limit for Segment %d: ", i);
        scanf("%d %d", &segmentTable.entries[i].base, &segmentTable.entries[i].limit);

    }

    while (1) {
        printf("\nEnter a logical address (Segment Number Offset) (-1 to exit): ");
        scanf("%d", &logicalAddress);

        if (logicalAddress == -1) {

            break;
        }

        printf("Enter segment number and offset: ");
        scanf("%d %d", &segmentNumber, &offset);



        if (segmentNumber < 0 || segmentNumber >= MAX_SEGMENTS || 
            offset < 0 || offset >= segmentTable.entries[segmentNumber].limit ||
            segmentTable.entries[segmentNumber].base == -1) {
            printf("Invalid logical address or segment not mapped correctly.\n");

            continue;
        }

        int base = segmentTable.entries[segmentNumber].base;
        int physicalAddress = base + offset;
        printf("Logical address [Segment %d, Offset %d] maps to physical address %d\n",
               segmentNumber, offset, physicalAddress);

    }

    printSegmentTable(&segmentTable);

    return 0;
}