#include <stdio.h>

struct Process {
    int pid,at,bt,remainingTime,wt,tat;
};

void sortByat(struct Process proc[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (proc[i].at > proc[j].at) {
                struct Process temp = proc[i];
                proc[i] = proc[j];
                proc[j] = temp;
            }
        }
    }
}

void calculatePreemptiveSJF(struct Process proc[], int n) {
    int i;
    int completed = 0, currentTime = 0, minIndex = -1;
    int minRemainingTime = 2147483647; 
    float totalwt = 0, totaltat = 0;
    int isProcessSelected = 0;

    while (completed != n) {
        for (i = 0; i < n; i++) {
            if (proc[i].at <= currentTime && proc[i].remainingTime > 0 && proc[i].remainingTime < minRemainingTime) {
                minRemainingTime = proc[i].remainingTime;
                minIndex = i;
                isProcessSelected = 1;
            }
        }

        if (isProcessSelected == 0) {
            currentTime++;
            continue;
        }

        proc[minIndex].remainingTime--;
        minRemainingTime = proc[minIndex].remainingTime;

        if (proc[minIndex].remainingTime == 0) {
            completed++;
            isProcessSelected = 0;
            minRemainingTime = 2147483647;
            
            proc[minIndex].tat = currentTime + 1 - proc[minIndex].at;
            proc[minIndex].wt = proc[minIndex].tat - proc[minIndex].bt;

            totalwt += proc[minIndex].wt;
            totaltat += proc[minIndex].tat;
        }

        currentTime++;
    }

    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("Average Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);
}

int main() {
    int n;
    int i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process proc[n];
    for (i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &proc[i].at, &proc[i].bt);
        proc[i].remainingTime = proc[i].bt; 
        proc[i].wt = 0;
        proc[i].tat = 0;
    }

    sortByat(proc, n);
    calculatePreemptiveSJF(proc, n);

    return 0;
}


