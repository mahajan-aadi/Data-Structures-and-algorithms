#include<stdio.h>

// declaration of the ready queue

int main()
{
	int n,TQ,p,TIME=0;
	int temp[10],exist[10]={0};
	float total_wt=0,total_tat=0,Avg_WT,Avg_TAT;
	
	int id[10],AT[10],BT[10],WT[10],TAT[10];
	int queue[100];
	int front=-1;
	int rear=-1;

    
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time of the process\n");
    printf("AT BT\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&AT[i],&BT[i]);
        id[i]=i;
        temp[i]=BT[i];
    }
    printf("Enter the time quantum\n");
    scanf("%d",&TQ);
    // logic for round robin scheduling
    
    // insert first process
    // into ready queue
    
    if(front==-1)
    	front=0;
    rear=rear+1;
    queue[rear]=0;
    
    exist[0]=1;
    // until ready queue is empty
    while(front<=rear)
    {
    	int p;
    	p=queue[front];
    	front=front+1;
        if(BT[p]>=TQ)
        {
            BT[p]=BT[p]-TQ;
            TIME=TIME+TQ;
        }
        else
        {
            TIME=TIME+BT[p];
            BT[p]=0;
        }
        
        
        //if process is not exist 
        // in the ready queue even a single 
        // time then insert it if it arrive
        // at time 'TIME'
        for(int i=0;i<n;i++)
        {
            if(exist[i]==0 && AT[i]<=TIME)
            {
            	if(front==-1)
		     front=0;
	    	rear=rear+1;
	    	queue[rear]=i;
                exist[i]=1;
            }
        }
        // if process is completed
        if(BT[p]==0)
        {
            TAT[p]=TIME-AT[p];
            WT[p]=TAT[p]-temp[p];
            total_tat=total_tat+TAT[p];
            total_wt=total_wt+WT[p];
        }
        else
        {
		if(front==-1)
	    		front=0;
	    	rear=rear+1;
	    	queue[rear]=p;
        }
    }
    
    Avg_TAT=total_tat/n;
    Avg_WT=total_wt/n;
    
    // printing of the answer
    printf("ID WT TAT\n");
    for(int i=0;i<n;i++)
    {
        printf("%d  %d  %d\n",id[i],WT[i],TAT[i]);
    }
    printf("Average waiting time of the processes is : %f\n",Avg_WT);
    printf("Average turn around time of the processes is : %f\n",Avg_TAT);
    return 0;
}
