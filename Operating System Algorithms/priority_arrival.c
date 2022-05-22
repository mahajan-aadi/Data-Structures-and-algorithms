#include<stdio.h>
int main()
{
	int bt[20],p[20],a[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp;
	float avg_wt,avg_tat;
	printf("Enter number of process:");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{

		printf("P%d:",i+1);
		printf("Enter arrival time:");
		scanf("%d",&a[i]);
		printf("\nEnter Burst Time:");
		scanf("%d",&bt[i]);
		printf("Enter Priority:");
		scanf("%d",&pr[i]);
		printf("\n");
		p[i]=i+1;
	}
	//sorting of arrival times
	for(i=0;i<n;i++)
	{
		pos=i;
		for(j=i+1;j<n;j++)
		{
			if(a[j]<a[pos])
				pos=j;
		}
		temp=bt[i];
		bt[i]=bt[pos];
		bt[pos]=temp;
		temp=p[i];
		p[i]=p[pos];
		p[pos]=temp;
		temp=pr[i];
		pr[i]=pr[pos];
		pr[pos]=temp;
	}
	wt[0]=0;
	for(i=1;i<n;i++)
	{
		wt[i]=0;
		for(j=0;j<i;j++)
			wt[i]+=bt[j];
		total+=wt[i]-a[i];
	}
	avg_wt=(float)total/n;
	total=0;
	printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\tPriority");
	for(i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i]-a[i];
		total+=tat[i];
		printf("\nP[%d]\t\t%d\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i]-a[i],tat[i],pr[i]);
	}
	avg_tat=(float)total/n;
	printf("\nAverage Waiting Time=%f",avg_wt);
	printf("\nAverage Turnaround Time=%f\n",avg_tat);
}


