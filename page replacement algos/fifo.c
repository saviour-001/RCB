#include <stdio.h>

void fcfsPageReplacement(int pages[], int numPages, int numFrames) {
    int frames[numFrames], faults = 0, index = 0;
    int isPageInFrame;

    // Initialize frames
    for (int i = 0; i < numFrames; i++) {
        frames[i] = -1;
    }

    printf("Page Replacement Process (FCFS):\n");
    for (int i = 0; i < numPages; i++) {
        isPageInFrame = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < numFrames; j++) {
            if (frames[j] == pages[i]) {
                isPageInFrame = 1;
                break;
            }
        }

        // If the page is not in a frame, replace the oldest one
        if (!isPageInFrame) {
            frames[index] = pages[i];
            index = (index + 1) % numFrames;
            faults++;
        }

        // Display the current state of frames
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
}

int main() {
    int pages[] = {1, 3, 0, 3, 5, 6, 3};
    int numPages = sizeof(pages) / sizeof(pages[0]);
    int numFrames = 3;

    fcfsPageReplacement(pages, numPages, numFrames);
    return 0;
}