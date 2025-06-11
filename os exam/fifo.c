#include <stdio.h>

int main() {
    int pages[100], frames[10];
    int n, frameCount, pageFaults = 0, nextToReplace = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    // Initialize frames with -1 (empty)
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\t\tStatus\n");

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in frame
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        printf("%d\t", pages[i]);

        // If page not found → replace (FIFO)
        if (!found) {
            frames[nextToReplace] = pages[i];
            nextToReplace = (nextToReplace + 1) % frameCount;
            pageFaults++;

            // Print frames
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\t\tPage Fault\n");
        } else {
            // Print frames
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] != -1)
                    printf("%d ", frames[j]);
                else
                    printf("- ");
            }
            printf("\t\tHit\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}
