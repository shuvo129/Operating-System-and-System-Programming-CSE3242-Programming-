#include<stdio.h>
#include<conio.h>
struct process{
    float WT,AT,BT,TAT;
};

struct process a[10];

int main(){
    int i,processNumber,count=0,t=0,short_P;

    float burstTime[15],arrivalTime[15];
    float totalTT=0,totalWT=0;

    printf("\n\nEnter the number of the Processes: ");
    scanf("%d",&processNumber);

    printf("Enter Arrival Time and Burst Time for %d Process: ",processNumber);
    printf("\n\n Pr AT BT\n");

    for(i=0;i<processNumber;i++){
            printf(" P%d  ",i+1);
            scanf("%f %f",&a[i].AT,&a[i].BT);

        // copying the burst time in
        // a burstTime array for the further use
        // in calculation of WT
        arrivalTime[i]=a[i].AT;
        burstTime[i]=a[i].BT;
    }

    // we initialize the burst time
    // of a process with the maximum
    a[9].BT=10000;
    // loop will be execute until all the process
    // complete so we use count!= number of
    // the process
    for(t=0;count!=processNumber;t++)
    {
        // for finding min burst
        // it is useful
        short_P=9;
        for(i=0;i<processNumber;i++){
            if(a[i].BT<a[short_P].BT && (a[i].AT<=t && a[i].BT>0)){
                short_P=i;
                //printf("\n%d",short_P);
            }

        }

        a[short_P].BT=a[short_P].BT-1;

        // if any process is completed
        if(a[short_P].BT==0)
        {
            // one process complete
            count++;
            a[short_P].WT=t+1-a[short_P].AT-burstTime[short_P];
            a[short_P].TAT=t+1-a[short_P].AT;

            //printf("\n%d",t+1);


            // total calculation
            totalWT=totalWT+a[short_P].WT;
            totalTT=totalTT+a[short_P].TAT;
        }



    }

    // printing of the answer
    printf("\n\n\tProcess \tArrival_Time \tBurst_Time \tTurnaround_Time \tWaiting_Time");
    //printf("Id WT TAT\n");
    for(int i=0;i<processNumber;i++){
        //printf("%d\t%d\t%d\n",i+1,a[i].WT,a[i].TAT);
        printf("\n\t  P%d\t\t     %0.1f\t   %0.1f\t\t      %0.1f\t\t   %0.1f",i+1,arrivalTime[i],burstTime[i],a[i].TAT,a[i].WT);
    }

    printf("\n\nAverage Turnaround Time is: %f",totalTT/processNumber);
    printf("\nAverage Waiting Time is: %f",totalWT/processNumber);

    getch();

}
