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

    int frames[numFrames], faults = 0, isPageInFrame;

    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    printf("\nPage Replacement Process (Optimal):\n");

    for (int i = 0; i < numPages; i++) {
        isPageInFrame = 0;

        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }

        if (!isPageInFrame) {
            if (i < numFrames) {
                frames[i] = pages[i];
            } else {
                int farthest = i, replaceIndex = -1;

                for (int j = 0; j < numFrames; j++) {
                    int found = 0;

                    for (int k = i + 1; k < numPages; k++) {
                        if (frames[j] == pages[k]) {
                            found = 1;
                            if (k > farthest) {
                                farthest = k;
                                replaceIndex = j;
                            }
                            break;
                        }
                    }

                    if (!found) {
                        replaceIndex = j;
                        break;
                    }
                }

                if (replaceIndex == -1) {
                    replaceIndex = 0; 
                }
                frames[replaceIndex] = pages[i];
            }
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
