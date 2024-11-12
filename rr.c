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

void calculateRoundRobin(struct Process proc[], int n, int quantum) {
    int i;
    int currentTime = 0;
    int completed = 0;
    float totalwt = 0, totaltat = 0;
    int queue[n], front = 0, rear = 0;

    for (i = 0; i < n; i++) {
        queue[rear++] = i; 
    }

    while (completed != n) {
        int idx = queue[front++];
        if (front == n) front = 0; 

        if (proc[idx].remainingTime > quantum) {
            proc[idx].remainingTime -= quantum;
            currentTime += quantum;
        } else {
            currentTime += proc[idx].remainingTime;
            proc[idx].remainingTime = 0;
            completed++;
            
            proc[idx].wt = currentTime - proc[idx].at - proc[idx].bt;
            proc[idx].tat = currentTime - proc[idx].at;

            totalwt += proc[idx].wt;
            totaltat += proc[idx].tat;
        }

        for (i = 0; i < n; i++) {
            if (proc[i].at <= currentTime && proc[i].remainingTime > 0 && !isInQueue(queue, front, rear, i)) {
                queue[rear++] = i;
                if (rear == n) rear = 0; 
            }
        }

        if (proc[idx].remainingTime > 0) {
            queue[rear++] = idx;
            if (rear == n) rear = 0; 
        }
    }

    printf("PID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", proc[i].pid, proc[i].at, proc[i].bt, proc[i].wt, proc[i].tat);
    }

    printf("Average Waiting Time: %.2f\n", totalwt / n);
    printf("Average Turnaround Time: %.2f\n", totaltat / n);
}

int isInQueue(int queue[], int front, int rear, int pid) {
    for (int i = front; i != rear; i = (i + 1) % rear) {
        if (queue[i] == pid) return 1;
    }
    return 0;
}

int main() {
    int n;
    int quantum;
    int i;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &quantum);

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
    calculateRoundRobin(proc, n, quantum);

    return 0;
}


