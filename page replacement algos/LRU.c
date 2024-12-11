#include <stdio.h>

int main() {
    int numPages, numFrames;

    printf("Enter the number of pages: ");
    scanf("%d", &numPages);

    int pages[numPages];

    printf("Enter the page sequence:\n");
    for (int i = 0; i < numPages; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    int frames[numFrames], time[numFrames], faults = 0, count = 0;
    int isPageInFrame, leastRecentlyUsed;

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    printf("\nPage Replacement Process (LRU):\n");

    for (int i = 0; i < numPages; i++) {
        isPageInFrame = 0;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                isPageInFrame = 1;
                time[j] = ++count; 
                break;
            }
        }

        if (!isPageInFrame) {
            leastRecentlyUsed = 0;

            for (int j = 1; j < numFrames; j++) {
                if (time[j] < time[leastRecentlyUsed]) {
                    leastRecentlyUsed = j;
                }
            }

            frames[leastRecentlyUsed] = pages[i];
            time[leastRecentlyUsed] = ++count;
            faults++;
        }

        printf("Page %d -> Frames: ", pages[i]);
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] != -1)
                printf("%d ", frames[j]);
            else
                printf("- ");
        }
        printf("\n");
    }

    printf("\nTotal Page Faults: %d\n", faults);

    return 0;
}
