#include <stdio.h>

struct Process {
    int id, bt, wt, tat, at;
};

void calculatewt(struct Process processes[], int n) {
    processes[0].wt = 0; 

    for (int i = 1; i < n; i++) {
        processes[i].wt = processes[i - 1].wt + processes[i - 1].bt - processes[i].at;
        
        if (processes[i].wt < 0) {
            processes[i].wt = 0;
        }
    }
}

void calculatetat(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].tat = processes[i].wt + processes[i].bt;
    }
}

void sortProcessesByat(struct Process processes[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].at > processes[j].at) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
}

void displayProcesses(struct Process processes[], int n) {
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].id, processes[i].at,
               processes[i].bt, processes[i].wt, processes[i].tat);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].at);
        printf("Enter burst time for process %d: ", processes[i].id);
        scanf("%d", &processes[i].bt);
    }

    sortProcessesByat(processes, n);

    calculatewt(processes, n);
    calculatetat(processes, n);

    displayProcesses(processes, n);

    float totalwt = 0, totaltat = 0;
    for (int i = 0; i < n; i++) {
        totalwt += processes[i].wt;
        totaltat += processes[i].tat;
    }
    printf("\nAverage Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);

    return 0;
}
