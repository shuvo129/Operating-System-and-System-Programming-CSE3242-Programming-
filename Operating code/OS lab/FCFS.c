#include<stdio.h>
//#include<conio.h>


int main()
{
    int i,processNumber;
    float burstTime[15],arrivalTime[15],completionTime[15],turnaroundTime[15],waitingTime[15];
    float totalTT=0,totalWT=0,sum=0;

    printf("\n\nEnter the number of Processes: ");
    scanf("%d",&processNumber);

    printf("Enter Arrival Time and Burst Time for %d Process: ",processNumber);

    printf("\n\n Pr AT BT\n");

    for(i=0; i<processNumber; i++){
        printf(" P%d  ",i+1);
        scanf("%f %f",&arrivalTime[i],&burstTime[i]);
        sum=sum+burstTime[i];
        completionTime[i]=sum;

        turnaroundTime[i]=completionTime[i]-arrivalTime[i];
        waitingTime[i]=turnaroundTime[i]-burstTime[i];
    }

    printf("\n\n\tProcess \tArrival_Time \tBurst_Time \tTurnaround_Time \tWaiting_Time");

    for(i=0; i<processNumber; i++){
            printf("\n\t  P%d\t\t     %0.1f\t   %0.1f\t\t      %0.1f\t\t   %0.1f",i+1,arrivalTime[i],burstTime[i],turnaroundTime[i],waitingTime[i]);

            totalTT=totalTT+turnaroundTime[i];
            totalWT=totalWT+waitingTime[i];


    }

    printf("\n\nAverage Turnaround Time is: %f",totalTT/processNumber);
    printf("\nAverage Waiting Time is: %f",totalWT/processNumber);




return 0;

    //getch();
}
