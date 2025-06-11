#include <stdio.h>

int findLRU(int time[], int n) {
    int min = time[0], pos = 0;
    for (int i = 1; i < n; i++) {
        if (time[i] < min) {
            min = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int frames[10], time[10];
    int pages[100], n, frameCount;
    int counter = 0, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    printf("\nPage\tFrames\t\t\tStatus\n");

    for (int i = 0; i < n; i++) {
        int page = pages[i], found = 0;

        // Check for hit
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == page) {
                found = 1;
                time[j] = ++counter;
                break;
            }
        }

        // On fault
        if (!found) {
            int pos = -1;
            // Check for empty frame
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    pos = j;
                    break;
                }
            }

            // Replace LRU if no empty frame
            if (pos == -1) {
                pos = findLRU(time, frameCount);
            }

            frames[pos] = page;
            time[pos] = ++counter;
            faults++;

            printf("%d\t", page);
            for (int k = 0; k < frameCount; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\t\tPage Fault\n");
        } else {
            printf("%d\t", page);
            for (int k = 0; k < frameCount; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\t\tHit\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", faults);
    return 0;
}
