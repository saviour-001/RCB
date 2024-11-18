#include <stdio.h>

struct Process {
    int id,at,bt,remaining_time,wt,tat,completion_time;
};

int main() {
    int n, i, time_quantum, current_time = 0, completed = 0;
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
        processes[i].remaining_time = processes[i].bt; 
        processes[i].wt = 0;
    }

    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);

    while (completed < n) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].at <= current_time) {
                if (processes[i].remaining_time > time_quantum) {
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;

                    processes[i].completion_time = current_time;
                    processes[i].tat = processes[i].completion_time - processes[i].at;
                    processes[i].wt = processes[i].tat - processes[i].bt;

                    total_wt += processes[i].wt;
                    total_tat += processes[i].tat;

                    completed++;
                }
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].id, processes[i].at, processes[i].bt,processes[i].completion_time, processes[i].wt, processes[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
