#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
// Structure to represent a process
struct Process
{
    int pid;           // Process ID
    int arrivalTime;   // Arrival Time
    int burstTime;     // Burst Time
    int remainingTime; // Remaining Burst Time
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};
// Function to simulate SJF (Preemptive) Scheduling
void sjfPreemptive(struct Process p[], int n)
{
    int completedProcesses = 0, currentTime = 0, shortestJob;
    int minBurstTime;
    bool isProcessRunning = false;
    while (completedProcesses < n)
    {
        shortestJob = -1;
        minBurstTime = INT_MAX;
        // Find the process with the shortest remaining time at currentTime
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0)
            {
                if (p[i].remainingTime < minBurstTime)
                {
                    minBurstTime = p[i].remainingTime;
                    shortestJob = i;
                }
            }
        }
        if (shortestJob == -1)
        {
            currentTime++; // If no process is available, move time forward
            continue;
        }
        // Execute the selected process for one unit of time
        p[shortestJob].remainingTime--;
        currentTime++;
        // If process is completed
        if (p[shortestJob].remainingTime == 0)
        {
            completedProcesses++;
            p[shortestJob].completionTime = currentTime;
            p[shortestJob].turnaroundTime = p[shortestJob].completionTime - p[shortestJob].arrivalTime;
            p[shortestJob].waitingTime = p[shortestJob].turnaroundTime - p[shortestJob].burstTime;
        }
    }
}
// Function to display results
void displayResults(struct Process p[], int n)
{
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
    }
    // Calculate average turnaround time and waiting time
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgTurnaroundTime += p[i].turnaroundTime;
        avgWaitingTime += p[i].waitingTime;
    }
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime / n);
}
int main()
{
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process p[n];
    // Input process details
    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].pid = i + 1;                    // Assign process ID
        p[i].remainingTime = p[i].burstTime; // Initialize remaining burst time
    }
    // Simulating SJF (Preemptive) Scheduling
    sjfPreemptive(p, n);
    // Displaying results
    displayResults(p, n);
    return 0;
}