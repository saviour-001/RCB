#include <stdio.h>

struct Process {
    int id,at,bt,remainingTime,priority,wt,tat;
};

int findHighestPriorityProcess(struct Process proc[], int n, int currentTime) {
    int highestPriorityIndex = -1;
    int highestPriority = 10000; 
    
    for (int i = 0; i < n; i++) {
        if (proc[i].at <= currentTime && proc[i].remainingTime > 0) {
            if (proc[i].priority < highestPriority) {
                highestPriority = proc[i].priority;
                highestPriorityIndex = i;
            }
            else if (proc[i].priority == highestPriority) {
                if (proc[i].at < proc[highestPriorityIndex].at) {
                    highestPriorityIndex = i;
                }
            }
        }
    }
    return highestPriorityIndex;
}

int main() {
    int n, totalTime = 0, completed = 0;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process proc[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for process %d:\n", i + 1);
        proc[i].id = i + 1;
        printf("enter Arrival Time for process %d : ",i+1);
        scanf("%d", &proc[i].at);
        printf("enter Burst Time for process %d : ",i+1);
        scanf("%d", &proc[i].bt);
        printf("enter Priority for process %d ",i+1);
        scanf("%d", &proc[i].priority);

        proc[i].remainingTime = proc[i].bt;
        proc[i].wt = 0;
        proc[i].tat = 0;
    }

    int currentTime = 0;
    while (completed != n) {
        int highestPriorityIndex = findHighestPriorityProcess(proc, n, currentTime);
        if (highestPriorityIndex == -1) {
            currentTime++;
            continue;
        }
        
        proc[highestPriorityIndex].remainingTime--;
        currentTime++;

        if (proc[highestPriorityIndex].remainingTime == 0) {
            completed++;
            proc[highestPriorityIndex].tat = currentTime - proc[highestPriorityIndex].at;
            proc[highestPriorityIndex].wt = proc[highestPriorityIndex].tat - proc[highestPriorityIndex].bt;

            avgwt += proc[highestPriorityIndex].wt;
            avgtat += proc[highestPriorityIndex].tat;
        }
    }

    avgwt /= n;
    avgtat /= n;

    printf("\nProcess ID\tArrival Time\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",proc[i].id,proc[i].at,proc[i].bt,proc[i].priority,proc[i].wt,proc[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", avgwt);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat);

    return 0;
}
