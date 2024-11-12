#include <stdio.h>

struct Process {
    int pid,bt,at,priority,remainingTime,completionTime;
    int wt,tat,isCompleted;     
};


int findHighestPriorityProcess(struct Process processes[], int n, int currentTime) {
    int maxPriorityIndex = -1;
    for (int i = 0; i < n; i++) {
        if (processes[i].at <= currentTime && processes[i].isCompleted == 0) {
            if (maxPriorityIndex == -1 || processes[i].priority > processes[maxPriorityIndex].priority) {
                maxPriorityIndex = i;
            }
        }
    }
    return maxPriorityIndex;
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];  

    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1;
        printf("\nEnter burst time, arrival time, and priority for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].bt, &processes[i].at, &processes[i].priority);
        processes[i].remainingTime = processes[i].bt;
        processes[i].isCompleted = 0; 
    }

    int currentTime = 0, completed = 0;
    float totalwt = 0, totaltat = 0;

    while (completed < n) {
        int p_index = findHighestPriorityProcess(processes, n, currentTime);

        if (p_index == -1) { 
            currentTime++;
        } else {
            processes[p_index].remainingTime--;
            currentTime++;

            if (processes[p_index].remainingTime == 0) {
                processes[p_index].isCompleted = 1;  
                completed++;

                processes[p_index].completionTime = currentTime;
                processes[p_index].tat = processes[p_index].completionTime - processes[p_index].at;
                processes[p_index].wt = processes[p_index].tat - processes[p_index].bt;

                totalwt += processes[p_index].wt;
                totaltat += processes[p_index].tat;
            }
        }
    }

    printf("\nProcess\tBurst Time\tArrival Time\tPriority\tWaiting Time\tTurnaround Time");
    for (int i = 0; i < n; i++) {
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d", processes[i].pid, processes[i].bt, processes[i].at,
               processes[i].priority, processes[i].wt, processes[i].tat);
    }

    printf("\n\nAverage Waiting Time: %.2f", totalwt / n);
    printf("\nAverage Turnaround Time: %.2f\n", totaltat / n);

    return 0;
}
