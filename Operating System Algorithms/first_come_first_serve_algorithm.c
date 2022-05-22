#include<stdio.h>
int main()
{
	//Initializing all the required values
	int n,bt[20],wt[20],tat[20],i,j;
	float avwt,avtat;
	printf("Enter number of processes(maximum 20):");
	//Asking number of processors from user
	scanf("%d",&n);

	printf("\nEnter process burst time\n");
	//Asking burst time of each process from user
	for (i=0;i<n;i++)
	{
		printf("P[%d]:",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	//waiting time is burst time of all previous procceses
	for (i=0;i<n;i++)
	{
		wt[i]=0;
		for (j=0;j<i;j++)
			wt[i]+=bt[j];
	}
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time");
	//printing values
	for (i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		avwt+=wt[i];
		avtat+=tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
	}
	avwt/=(float)n;
	avtat/=(float)n;
	printf("\nAverage Waiting time=%f\n",avwt);
	printf("\nAverage Turnaround time=%f\n",avtat);
}
