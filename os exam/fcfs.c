#include <stdio.h>

// Structure to represent a process
struct Process {
    int pid;          // Process ID
    int arrivalTime;  // Arrival Time
    int burstTime;    // Burst Time
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};

// Function to sort processes by Arrival Time
void sortByArrival(struct Process p[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].arrivalTime > p[j + 1].arrivalTime) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to simulate FCFS scheduling
void fcfsScheduling(struct Process p[], int n) {
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].arrivalTime) {
            currentTime = p[i].arrivalTime;
        }
        p[i].completionTime = currentTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        currentTime = p[i].completionTime;
    }
}

// Function to display the result
void displayResults(struct Process p[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    // Calculating average turnaround time and waiting time
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
        avgTurnaroundTime += p[i].turnaroundTime;
        avgWaitingTime += p[i].waitingTime;
    }
    
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime / n);
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].pid = i + 1;  // Assign process ID
    }

    // Sorting processes by arrival time
    sortByArrival(p, n);

    // Simulating FCFS scheduling
    fcfsScheduling(p, n);

    // Displaying results
    displayResults(p, n);

    return 0;
}