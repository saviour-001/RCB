#include <stdio.h>
// Structure to represent a process
struct Process
{
    int pid;         // Process ID
    int arrivalTime; // Arrival Time
    int burstTime;   // Burst Time
    int priority;    // Priority (lower value = higher priority)
    int completionTime;
    int turnaroundTime;
    int waitingTime;
};
// Function to sort processes based on priority (Non-Preemptive)
void sortByPriority(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // Sorting by priority (lower value = higher priority)
            // If same priority, sort by arrival time
            if (p[j].priority < p[i].priority ||
                (p[j].priority == p[i].priority && p[j].arrivalTime < p[i].arrivalTime))
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
// Function to calculate scheduling details
void priorityScheduling(struct Process p[], int n)
{
    sortByPriority(p, n);
    int currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        if (currentTime < p[i].arrivalTime)
            currentTime = p[i].arrivalTime; // If CPU is idle, wait for process arrival
        p[i].completionTime = currentTime + p[i].burstTime;
        p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
        currentTime = p[i].completionTime; // Move time forward
    }
}
// Function to display results
void displayResults(struct Process p[], int n)
{
    printf("\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,
               p[i].priority, p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
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
        printf("Enter arrival time, burst time, and priority for process %d: ", i + 1);
        scanf("%d %d %d", &p[i].arrivalTime, &p[i].burstTime, &p[i].priority);
        p[i].pid = i + 1; // Assign process ID
    }
    // Simulating Priority Scheduling (Non-Preemptive)
    priorityScheduling(p, n);
    // Displaying results
    displayResults(p, n);
    return 0;
}