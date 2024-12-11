#include <stdio.h>
#include <limits.h> 

struct Process {
    int id,at,bt,remaining_time,completion_time,wt,tat; 
};

int main() {
    int n, i, current_time = 0, completed = 0;
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
    }

    while (completed < n) {
        int shortest_job = -1;
        int min_remaining_time = INT_MAX;

        for (i = 0; i < n; i++) {
            if (processes[i].at <= current_time && processes[i].remaining_time > 0 &&
                processes[i].remaining_time < min_remaining_time) {
                shortest_job = i;
                min_remaining_time = processes[i].remaining_time;
            }
        }

        if (shortest_job == -1) {
            current_time++;
        } else {
            processes[shortest_job].remaining_time--;
            current_time++;

            if (processes[shortest_job].remaining_time == 0) {
                completed++;
                processes[shortest_job].completion_time = current_time;
                processes[shortest_job].tat =
                    processes[shortest_job].completion_time - processes[shortest_job].at;
                processes[shortest_job].wt =
                    processes[shortest_job].tat - processes[shortest_job].bt;

                total_wt += processes[shortest_job].wt;
                total_tat += processes[shortest_job].tat;
            }
        }
    }

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",processes[i].id,processes[i].at,processes[i].bt,processes[i].completion_time,processes[i].wt,processes[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}
