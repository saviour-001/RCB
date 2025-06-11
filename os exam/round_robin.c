#include <stdio.h>
struct Process
{
    int pid, arrivalTime, burstTime, remainingTime, completionTime, turnaroundTime, waitingTime;
};
void roundRobin(struct Process p[], int n, int timeQuantum)
{
    int currentTime = 0, completed = 0;
    while (completed < n)
    {
        for (int i = 0; i < n; i++)
        {
            if (p[i].remainingTime > 0 && p[i].arrivalTime <= currentTime)
            {
                int execTime = (p[i].remainingTime > timeQuantum) ? timeQuantum : p[i].remainingTime;
                currentTime += execTime;
                p[i].remainingTime -= execTime;
                if (p[i].remainingTime == 0)
                {
                    completed++;
                    p[i].completionTime = currentTime;
                    p[i].turnaroundTime = p[i].completionTime - p[i].arrivalTime;
                    p[i].waitingTime = p[i].turnaroundTime - p[i].burstTime;
                }
            }
        }
    }
}
void displayResults(struct Process p[], int n)
{
    float avgTAT = 0, avgWT = 0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,
               p[i].completionTime, p[i].turnaroundTime, p[i].waitingTime);
        avgTAT += p[i].turnaroundTime;
        avgWT += p[i].waitingTime;
    }
    printf("\nAvg TAT: %.2f | Avg WT: %.2f\n", avgTAT / n, avgWT / n);
}
int main()
{
    int n, timeQuantum;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter AT & BT for P%d: ", i + 1);
        scanf("%d %d", &p[i].arrivalTime, &p[i].burstTime);
        p[i].pid = i + 1;
        p[i].remainingTime = p[i].burstTime;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &timeQuantum);

    roundRobin(p, n, timeQuantum);
    displayResults(p, n);

    return 0;
}