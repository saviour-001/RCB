#include <stdio.h>
#include <limits.h>
// Structure to represent a process
struct Process
{
    int pid, arrivalTime, burstTime, remainingTime, priority, completionTime, turnaroundTime, waitingTime;
};
// Function to find the highest priority process at a given time
int findHighestPriority(struct Process p[], int n, int currentTime)
{
    int highestPriorityIndex = -1, highestPriority = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (p[i].arrivalTime <= currentTime && p[i].remainingTime > 0 && p[i].priority < highestPriority)
        {
            highestPriority = p[i].priority;
            highestPriorityIndex = i;
        }
    }
    return highestPriorityIndex;
}
// Function to simulate Preemptive Priority Scheduling
void priorityPreemptiveScheduling(struct Process p[], int n)
{
    int completedProcesses = 0, currentTime = 0;
    while (completedProcesses < n)
    {
        int highestPriorityProcess = findHighestPriority(p, n, currentTime);
        if (highestPriorityProcess == -1)
        {
            currentTime++;
            continue;
        }
        p[highestPriorityProcess].remainingTime--;
        currentTime++;
        if (p[highestPriorityProcess].remainingTime == 0)
        {
            completedProcesses++;
            p[highestPriorityProcess].completionTime = currentTime;
            p[highestPriorityProcess].turnaroundTime = currentTime - p[highestPriorityProcess].arrivalTime;
            p[highestPriorityProcess].waitingTime = p[highestPriorityProcess].turnaroundTime - p[highestPriorityProcess].burstTime;
        }
    }
}
// Function to display results
void displayResults(struct Process p[], int n)
{
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    printf("\nPID\tArrival\tBurst\tPriority\tCompletion\tTurnaround\tWaiting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime, p[i].priority,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
        avgTurnaroundTime += p[i].turnaroundTime;
        avgWaitingTime += p[i].waitingTime;
    }
    printf("\nAverage Turnaround Time: %.2f\n", avgTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", avgWaitingTime / n);
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
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].pid = i + 1;
        p[i].remainingTime = p[i].burstTime;
    }
    // Simulating Preemptive Priority Scheduling
    priorityPreemptiveScheduling(p, n);
    // Displaying results
    displayResults(p, n);
    return 0;
}