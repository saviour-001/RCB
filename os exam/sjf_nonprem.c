#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

// Structure to represent a process
struct Process {
    int pid;          // Process ID
    int arrivalTime;  // Arrival Time 
    int burstTime;    // Burst Time
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool completed;   // Flag to check if process is completed
};

// Function to find the shortest job available at a given time
int findShortestJob(struct Process p[], int n, int currentTime) {
    int shortestIndex = -1;
    int minBurstTime = INT_MAX;  // Using INT_MAX from limits.h

    for (int i = 0; i < n; i++) {
        if (!p[i].completed && p[i].arrivalTime <= currentTime) {   
            if (p[i].burstTime < minBurstTime) {
                minBurstTime = p[i].burstTime;
                shortestIndex = i;
            }
        }
    }
    return shortestIndex;
}

// Function to simulate SJF (Non-Preemptive) Scheduling
void sjfScheduling(struct Process p[], int n) {
    int completedProcesses = 0, currentTime = 0;

    while (completedProcesses < n) {
        int shortestJob = findShortestJob(p, n, currentTime);
        if (shortestJob == -1) {
            currentTime++;  // If no process is available, move time forward
            continue;
        }

        // Process execution
        p[shortestJob].completionTime = currentTime + p[shortestJob].burstTime;
        p[shortestJob].turnaroundTime = p[shortestJob].completionTime - p[shortestJob].arrivalTime;
        p[shortestJob].waitingTime = p[shortestJob].turnaroundTime - p[shortestJob].burstTime;
        p[shortestJob].completed = true;

        currentTime = p[shortestJob].completionTime;
        completedProcesses++;
    }
}

// Function to display results
void displayResults(struct Process p[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }

    // Calculate average turnaround time and waiting time
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
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
        p[i].completed = false;
    }

    // Simulating SJF (Non-Preemptive) Scheduling
    sjfScheduling(p, n);

    // Displaying results
    displayResults(p, n);

    return 0;
}