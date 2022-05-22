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



//directed
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

int stack[MAX],top=0;
void push(int data)
{
    if(top==MAX)
    {
        printf("overflow \n");
        return -1;
    }
    stack[top++]=data;
}
int pop()
{
    if(top==0)
    {
        printf("underflow \n");
        return -1;
    }
    int data=stack[--top];
    return data;
}
void dfs()
{
    int cnt=0;
    int v,i;
    int arr[MAX];
    visited[0]=1;
    arr[cnt++]=0;
    v=0;

    while(cnt<MAX)
    {
        i=0;
        for(int v1=0;v1<MAX;v1++)
        {
            if(v1==v)
                continue;
            if(matrix[v][v1]==1)
            {
                if(visited[v1]!=1)
                {
                    push(v);
                    visited[v1]=1;
                    arr[cnt++]=v1;
                    v=v1;
                    break;
                }
            }
            i++;
        }
        if(i==MAX-1)
        {
            v=pop();
        }
    }
    for(int i=0;i<MAX;i++)
        printf("%d  ",arr[i]);
}
int main()
{
    dfs();
}

