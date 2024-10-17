#include<stdio.h>
#include<conio.h>

struct process{
    int id,AT,BT,WT,TAT;
};

struct process a[10];

// declaration of the ready queue
int queue[100];
int front=-1;
int rear=-1;

// function for insert the element
// into queue
void insert(int n){
    if(front==-1)
     front=0;
    rear=rear+1;
    queue[rear]=n;
}

// function for Delete the
// element from queue
int Delete(){
    int n;
    n=queue[front];
    front=front+1;
    return n;
}


int main()
{
    int processNumber,TQ,p,TIME=0;
    int burstTime[15],arrivalTime[15],exist[10]={0};
    float totalWT=0,totalTT=0;

    printf("\n\nEnter the number of the Processes: ");
    scanf("%d",&processNumber);

    printf("Enter Arrival Time and Burst Time for %d Process: ",processNumber);
    printf("\n\n Pr AT BT\n");

    for(int i=0;i<processNumber;i++){
            printf(" P%d  ",i+1);
            scanf("%d %d",&a[i].AT,&a[i].BT);
            a[i].id=i;

            arrivalTime[i]=a[i].AT;
            burstTime[i]=a[i].BT;
    }
    printf("Enter the Time Quantum: ");
    scanf("%d",&TQ);
    // logic for round robin scheduling

    // insert first process
    // into ready queue
    insert(0);
    exist[0]=1;
    // until ready queue is empty
    while(front<=rear)
    {
        p=Delete();
        if(a[p].BT>=TQ)
        {
            a[p].BT=a[p].BT-TQ;
            TIME=TIME+TQ;
        }
        else
        {
            TIME=TIME+a[p].BT;
            a[p].BT=0;
        }


        //if process is not exist
        // in the ready queue even a single
        // time then insert it if it arrive
        // at time 'TIME'
        for(int i=0;i<processNumber;i++)
        {
            if(exist[i]==0 && a[i].AT<=TIME)
            {
                insert(i);
                exist[i]=1;
            }
        }
        // if process is completed
        if(a[p].BT==0)
        {
            a[p].TAT=TIME-a[p].AT;
            a[p].WT=a[p].TAT-burstTime[p];
            totalTT=totalTT+a[p].TAT;
            totalWT=totalWT+a[p].WT;
        }
        else
        {
            insert(p);
        }
    }

    //Avg_TAT=totalTT/n;
    //Avg_WT=totalWT/n;

    // printing of the answer
    //printf("ID WT TAT\n");
    printf("\n\n\tProcess \tArrival_Time \tBurst_Time \tTurnaround_Time \tWaiting_Time");
    for(int i=0;i<processNumber;i++){
        //printf("%d  %d  %d\n",a[i].id,a[i].WT,a[i].TAT);
        printf("\n\t  P%d                 %d               %d                %d                   %d",i+1,arrivalTime[i],burstTime[i],a[i].TAT,a[i].WT);
    }
    printf("\n\nAverage Turnaround Time is: %f",totalTT/processNumber);
    printf("\nAverage Waiting Time is: %f",totalWT/processNumber);

    getch();
}
