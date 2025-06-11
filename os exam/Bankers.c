#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int processes, resources;
int allocation[MAX_PROCESSES][MAX_RESOURCES];
int maximum[MAX_PROCESSES][MAX_RESOURCES];
int available[MAX_RESOURCES];
int need[MAX_PROCESSES][MAX_RESOURCES];
int safeSequence[MAX_PROCESSES];

void calculateNeed() {
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            need[i][j] = maximum[i][j] - allocation[i][j];
        }
    }
}

int isSafe() {
    int work[MAX_RESOURCES], finish[MAX_PROCESSES] = {0};
    
    for (int i = 0; i < resources; i++)
        work[i] = available[i];

    int count = 0;
    while (count < processes) {
        int found = 0;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                int canAllocate = 1;
                for (int j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if (canAllocate) {
                    for (int j = 0; j < resources; j++)
                        work[j] += allocation[i][j];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) return 0;  // No safe sequence found
    }
    return 1;  // Safe sequence found
}

int main() {
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);

    printf("Enter allocation matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &allocation[i][j]);

    printf("Enter maximum matrix:\n");
    for (int i = 0; i < processes; i++)
        for (int j = 0; j < resources; j++)
            scanf("%d", &maximum[i][j]);

    printf("Enter available resources:\n");
    for (int i = 0; i < resources; i++)
        scanf("%d", &available[i]);

    calculateNeed();

    if (isSafe()) {
        printf("System is in a safe state.\nSafe sequence: ");
        for (int i = 0; i < processes; i++)
            printf("P%d ", safeSequence[i]);
        printf("\n");
    } else {
        printf("System is in an unsafe state! Deadlock may occur.\n");
    }

    return 0;
}