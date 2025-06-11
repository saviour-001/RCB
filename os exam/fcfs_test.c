#include<stdio.h>
struct process{
    int pid;
    int arrivalTime;
    int burstTime;
    int cTime;
    int tTime;
    int wTime;
};

void sortProcess(struct process p[],int n){

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arrivalTime>p[j+1].arrivalTime){
                struct process temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}
void fcfs(struct process p[],int n){
    int currentTime = 0;
    for(int i=0;i<n;i++){
        if(currentTime<p[i].arrivalTime){
            currentTime = p[i].arrivalTime;
        }
        p[i].cTime = currentTime+p[i].burstTime;
        p[i].tTime = p[i].cTime-p[i].arrivalTime;
        p[i].wTime = p[i].tTime -p[i].burstTime;
        currentTime =  p[i].cTime;
    }
}
void displayResults(struct process p[], int n) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");

    // Calculating average turnaround time and waiting time
    float avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrivalTime, p[i].burstTime,p[i].cTime, p[i].tTime, p[i].wTime);
        avgTurnaroundTime += p[i].tTime;
        avgWaitingTime += p[i].wTime;
    }
    
    printf("\nAverage Turnaround Time: %.2f", avgTurnaroundTime / n);
    printf("\nAverage Waiting Time: %.2f\n", avgWaitingTime / n);
}

int main(){
    int n;
    printf("Enter number of process: ");
    scanf("%d",&n);
    struct process p[n];

    for(int i=1;i<=n;i++){
        printf("Enter arrival Time and burst Time of process %d: ",i);
        scanf("%d %d",&p[i-1].arrivalTime,&p[i-1].burstTime);
        p[i-1].pid = i;
    }

    sortProcess(p,n);
    fcfs(p,n);
    displayResults(p,n);
    return 0;
}