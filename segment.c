#include <stdio.h>

#define MAX_SEGMENTS 10

int main() {
    int segmentCount;
    int base[MAX_SEGMENTS], limit[MAX_SEGMENTS];
    int segmentNumber, logicalAddress;

    printf("Enter the number of segments: ");
    scanf("%d", &segmentCount);

    for (int i = 0; i < segmentCount; i++) {
        printf("Enter base and limit for segment %d: ", i);
        scanf("%d %d", &base[i], &limit[i]);
    }

    printf("Enter segment number and logical address: ");
    scanf("%d %d", &segmentNumber, &logicalAddress);

    if (segmentNumber >= segmentCount || segmentNumber < 0) {
        printf("Invalid segment number!\n");
        return 1;
    }

    if (logicalAddress >= limit[segmentNumber]) {
        printf("Invalid logical address within segment!\n");
        return 1;
    }

    int physicalAddress = base[segmentNumber] + logicalAddress;

    printf("\nLogical Address: %d\n", logicalAddress);
    printf("Segment Number: %d\n", segmentNumber);
    printf("Base Address: %d\n", base[segmentNumber]);
    printf("Limit: %d\n", limit[segmentNumber]);
    printf("Physical Address: %d\n", physicalAddress);

    return 0;
}
