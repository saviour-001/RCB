#include <stdio.h>

struct Segment {
    int base;
    int size;
    int valid;  // To check if segment was successfully allocated
};

int main() {
    int totalMemory, numSegments;
    printf("Enter the memory size: ");
    scanf("%d", &totalMemory);

    printf("Enter the number of segments: ");
    scanf("%d", &numSegments);

    struct Segment segments[numSegments];
    int currentBase = 0;

    // Input segment sizes and assign base
    for (int i = 0; i < numSegments; i++) {
        int size;
        printf("Enter the segment %d size: ", i + 1);
        scanf("%d", &size);

        if (currentBase + size <= totalMemory) {
            segments[i].base = currentBase;
            segments[i].size = size;
            segments[i].valid = 1;
            currentBase += size;
        } else {
            printf("Segment %d cannot be allocated due to insufficient memory\n", i + 1);
            segments[i].valid = 0;
            segments[i].base = 0;
            segments[i].size = 0;
        }
    }

    // Print segment table
    printf("\nSEGMENT TABLE\n");
    printf("%-10s%-10s%-10s\n", "Segment", "BASE", "OFFSET");
    for (int i = 0; i < numSegments; i++) {
        if(segments[i].size>0){
            printf("Segment %d: %-4d     %-4d\n", i + 1, segments[i].base, segments[i].base + segments[i].size);
        }else{
            printf("Segment %d: N/A\tN/A\n",i+1);
        }
    }

    // Input logical address
    int segNum, offset;
    printf("\nEnter Segment number and Offset to find Physical Address: ");
    scanf("%d %d", &segNum, &offset);

    // Check validity
    if (segNum < 1 || segNum > numSegments || !segments[segNum - 1].valid || offset >= segments[segNum - 1].size) {
        printf("Invalid Segment Number or Offset\n");
    } else {
        int physicalAddress = segments[segNum - 1].base + offset;
        printf("Physical Address: %d\n", physicalAddress);
    }

    return 0;
}
