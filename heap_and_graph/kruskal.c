#include<stdio.h>

#define MAX 30
#define V 6

typedef struct edge
{
    int u,v,w;
}edge;

typedef struct edgelist
{
    edge data[MAX];
    int n;
}edgelist;

edgelist elist;

int G[V][V]= { { 0 , 10, 8, 0, 0, 0 },
                { 10, 0 , 3, 4, 2, 0 },
                { 8 , 3 , 0, 2, 3, 2 },
                { 0 , 4 , 2, 0, 4, 5 },
                { 0 , 2 , 3, 4, 0, 7 },
                { 0 , 0 , 2, 5, 7, 0 } };

edgelist spanlist;

void kruskal();
int find(int belongs[],int MAXertexno);
void union1(int belongs[],int c1,int c2);
void sort();
void print();

void main()
{
    int i,j,total_cost;
    kruskal();
    print();
}

void kruskal()
{
    int belongs[MAX],i,j,cno1,cno2;
    elist.n=0;

    for(i=1;i<V;i++)
        for(j=0;j<i;j++)
        {
            if(G[i][j]!=0)
            {
                elist.data[elist.n].u=i;
                elist.data[elist.n].v=j;
                elist.data[elist.n].w=G[i][j];
                elist.n++;
            }
        }

        sort();
        for(i=0;i<V;i++)
        belongs[i]=i;
        spanlist.n=0;
        for(i=0;i<elist.n;i++)
        {
            cno1=find(belongs,elist.data[i].u);
            cno2=find(belongs,elist.data[i].v);
            if(cno1!=cno2)
            {
                spanlist.data[spanlist.n]=elist.data[i];
                spanlist.n=spanlist.n+1;
                union1(belongs,cno1,cno2);
            }
        }
}

int find(int belongs[],int MAXertexno)
{
    return(belongs[MAXertexno]);
}

void union1(int belongs[],int c1,int c2)
{
    int i;
    for(i=0;i<V;i++)
    if(belongs[i]==c2)
    belongs[i]=c1;
}

void sort()
{
    int i,j;
    edge temp;
    for(i=1;i<elist.n;i++)
    for(j=0;j<elist.n-1;j++)
    if(elist.data[j].w>elist.data[j+1].w)
    {
        temp=elist.data[j];
        elist.data[j]=elist.data[j+1];
        elist.data[j+1]=temp;
    }
}

void print()
{
    int i,cost=0;
    printf("\nu->v\tw\n");
    for(i=0;i<spanlist.n;i++)
    {
        printf("\n%d->%d\t%d",spanlist.data[i].u,spanlist.data[i].v,spanlist.data[i].w);
        cost=cost+spanlist.data[i].w;
    }

    printf("\n\nCost of the spanning tree=%d",cost);
}
