#include <stdio.h>
#include<math.h>
int size = 0;
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}
void heapify(int array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l] < array[largest])
            largest = l;
        if (r < size && array[r] < array[largest])
            largest = r;
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}



void print_tree(int root[],int height_tree,int size)
{
    if(root==NULL)
        return;

    printf("  ");
    for(int i=0;i<=height_tree;i++)
    {
        for(int j=i;j<=height_tree;j++)
            printf("     ");
        print_level(root,0,i,size);
        printf("\n\n");
    }
}
void print_level(int root[],int i,int level,int size)
{
    if(i>=size)
        return;
    if(level==0)
        printf("%d",root[i]);

    printf(" ");
    print_level(root,2*i+1,level-1,size);
    printf(" ");
    print_level(root,2*i+2,level-1,size);
    printf(" ");
}



void printArray(int array[], int size)
{
    printf("\n");
    int level=log(size)+1;
    int ind=0;
    for (int i=0; i <= level; ++i)
    {
        for(int j=level;j>=i;j--)
            printf("  ");
        int max=1;
        for(int j=0;j<i;j++)
            max*=2;
        for(int j=0;j<max;j++)
        {
            //printf("//////%d->%d//////",i,max);
            if(ind==size)
                return;
            printf("%d  ",array[ind++]);

            if((j+1)>=max)
                break;

            if(ind==size)
                return;

            printf("%d  ",array[ind++]);
            printf("   ");
        }
        printf("\n");
    }
}
int main()
{
    int array[]={15,20,31,42,91,54,23,48,56,14,12};

    size=sizeof(array)/sizeof(int);
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(array, size, i);
    }

    printf("Min-Heap ");
    print_tree(array, log(size)+1,size);
}


