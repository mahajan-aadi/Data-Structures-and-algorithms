#include<stdio.h>
#include<string.h>


#define MAX 7
int matrix[MAX][MAX]={
                        {0,1,1,0,1,0,1},
                        {1,0,0,1,1,0,0},
                        {1,0,0,0,0,1,0},
                        {0,1,0,0,0,0,0},
                        {1,1,0,0,0,0,0},
                        {0,0,1,0,0,0,0},
                        {1,0,0,0,0,0,0},
                    };


/*
#define MAX 13

int matrix[MAX][MAX]={
                        {0,1,0,0,0,0,0,1,0,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,1,0,0,0,0,0,1,0,0,0},
                        {0,0,0,0,1,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,1,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,1,0,0,0,1,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,1,0,0,0,0},
                        {0,0,1,0,0,0,0,0,0,0,0,0,0},
                        {0,0,0,0,0,1,0,0,0,0,0,0,0},
                        {0,0,0,0,0,0,0,0,0,0,0,1,0},
                        {0,0,0,0,0,0,0,0,0,0,0,0,1},
                        {0,0,0,0,0,0,0,0,0,0,0,0,0}
                    };
*/
int visited[MAX]={0};

int queue[MAX],top=0,bottom=0;
void enqueue(int data)
{
    if(top==MAX)
    {
        printf("overflow \n");
        return -1;
    }
    queue[top++]=data;
}
int dequeue()
{
    if((top-bottom)==0)
    {
        printf("underflow \n");
        return -1;
    }
    int data=queue[bottom++];;
    return data;
}
void bsf()
{
    int cnt=0;
    int v;
    int arr[MAX];
    enqueue(0);
    visited[0]=1;
    arr[cnt++]=0;

    while(cnt<MAX)
    {
        v=dequeue();
        for(int v1=0;v1<MAX;v1++)
        {
            if(v1==v)
                continue;
            if(matrix[v][v1]==1)
            {
                if(visited[v1]!=1)
                {
                    enqueue(v1);
                    visited[v1]=1;
                    arr[cnt++]=v1;
                }
            }
        }
    }
    for(int i=0;i<MAX;i++)
        printf("%d  ",arr[i]);
}
int main()
{
    bsf();
}
