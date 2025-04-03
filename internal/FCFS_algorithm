#include <stdio.h>

struct Process {
    int id,at,bt,completion_time,wt,tat;
};

int main() {
    int n, i, j;
    float total_wt = 0, total_tat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter Arrival Time and Burst Time for each process:\n");
    for (i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Process %d:\n", processes[i].id);
        printf("Arrival Time: ");
        scanf("%d", &processes[i].at);
        printf("Burst Time: ");
        scanf("%d", &processes[i].bt);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (processes[j].at > processes[j + 1].at) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    int current_time = 0;
    for (i = 0; i < n; i++) {
        if (current_time < processes[i].at) {
            current_time = processes[i].at;
        }

        processes[i].completion_time = current_time + processes[i].bt;
        processes[i].tat = processes[i].completion_time - processes[i].at;
        processes[i].wt = processes[i].tat - processes[i].bt;

        current_time = processes[i].completion_time;
        total_wt += processes[i].wt;
        total_tat += processes[i].tat;
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].id,processes[i].at,processes[i].bt,processes[i].completion_time,processes[i].wt,processes[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
