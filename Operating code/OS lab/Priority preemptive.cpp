#include<stdio.h>
#include<conio.h>

struct process{
    int WT,AT,BT,TAT,PT;
};

struct process a[10];

int main()
{
    int processNumber,burstTime[15],arrivalTime[15],priority[15],t,count=0,short_p;
    float totalWT=0,totalTT=0;

    printf("\n\nEnter the number of the Processes: ");
    scanf("%d",&processNumber);
    printf("Enter Arrival Time, Burst Time and Priority for %d Process: ",processNumber);
    printf("\n\n Pr AT BT PT\n");
    for(int i=0;i<processNumber;i++){
            printf(" P%d  ",i+1);
            scanf("%d %d %d",&a[i].AT,&a[i].BT,&a[i].PT);

        // copying the burst time in
        // a burstTime array fot futher use
        arrivalTime[i]=a[i].AT;
        burstTime[i]=a[i].BT;
        priority[i]=a[i].PT;
    }

    // we initialize the burst time
    // of a process with maximum
    a[9].PT=10000;

    for(t=0;count!=processNumber;t++)
    {
        short_p=9;
        for(int i=0;i<processNumber;i++)
        {
            if(a[short_p].PT>a[i].PT && a[i].AT<=t && a[i].BT>0)
            {
                short_p=i;
            }
        }

        a[short_p].BT=a[short_p].BT-1;

        // if any process is completed
        if(a[short_p].BT==0)
        {
            // one process is completed
            // so count increases by 1
            count++;
            a[short_p].WT=t+1-a[short_p].AT-burstTime[short_p];
            a[short_p].TAT=t+1-a[short_p].AT;

            // total calculation
            totalWT=totalWT+a[short_p].WT;
            totalTT=totalTT+a[short_p].TAT;

        }
    }

    //Avg_WT=totalWT/processNumber;
    //Avg_TAT=totalTT/processNumber;

    // printing of the answer
    //printf("ID WT TAT\n");
    printf("\n\n\tProcess \tArrival_Time \tBurst_Time \tPriority \tTurnaround_Time \tWaiting_Time");
    for(int i=0;i<processNumber;i++){
        //printf("%d %d\t%d\n",i+1,a[i].WT,a[i].TAT);
        printf("\n\t  P%d                 %d               %d                 %d                 %d                    %d",i+1,arrivalTime[i],burstTime[i],priority[i],a[i].TAT,a[i].WT);
    }

    printf("\n\nAverage Turnaround Time is: %f",totalTT/processNumber);
    printf("\nAverage Waiting Time is: %f",totalWT/processNumber);


    getch();
}
