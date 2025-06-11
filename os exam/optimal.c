#include <stdio.h>

int findOptimal(int pages[], int frames[], int currentIndex, int n, int frameCount) {
    int farthest = currentIndex;
    int result = -1;

    for (int i = 0; i < frameCount; i++) {
        int j;
        for (j = currentIndex; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    result = i;
                }
                break;
            }
        }

        // If a page is never used again, replace it immediately
        if (j == n) {
            return i;
        }
    }

    return (result == -1) ? 0 : result;
}

int isHit(int frames[], int frameCount, int page) {
    for (int i = 0; i < frameCount; i++) {
        if (frames[i] == page)
            return 1;
    }
    return 0;
}

int main() {
    int n, frameCount;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &frameCount);

    int frames[frameCount];
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    int hit = 0, fault = 0;

    printf("\nPage\tFrames\t\tStatus\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", pages[i]);

        if (isHit(frames, frameCount, pages[i])) {
        hit++;
            for (int k = 0; k < frameCount; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\tHit\n");
        } else {
            int replaceIndex;
            fault++;

            // Find an empty frame first
            int placed = 0;
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    frames[j] = pages[i];
                    placed = 1;
                    break;
                }
            }

            // If no empty frame, use optimal replacement
            if (!placed) {
                replaceIndex = findOptimal(pages, frames, i + 1, n, frameCount);
                frames[replaceIndex] = pages[i];
            }

            for (int k = 0; k < frameCount; k++) {
                if (frames[k] != -1)
                    printf("%d ", frames[k]);
                else
                    printf("- ");
            }
            printf("\tFault\n");
        }
    }

    printf("\nTotal Hits: %d\n", hit);
    printf("Total Faults: %d\n", fault);
    return 0;
}
