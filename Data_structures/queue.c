#include<stdio.h>

int arr[10];
int top=0,bottom=0;
int n=10;

int main()
{
    enque(3);
    enque(4);
    enque(8);
    enque(12);
    enque(15);
    enque(18);
    enque(17);
    enque(16);
    print_array();
    deque();
    deque();
    print_array();
    enque(42);
    enque(62);
    print_array();
}
void deque()
{
    if(((top-bottom)!=0))
    {
        bottom++;
    }
    else
    {
        printf("queue empty");printf("\n");
    }
}
void enque(int data)
{
    if(top!=n)
    {
        arr[top++]=data;
    }
    else
    {
        printf("queue full");printf("\n");
    }
}
void print_array()
{
    for(int i=bottom;i!=top;i++)
    {
        int temp=arr[i];
        printf("%d,",temp);
    }
     printf("\n");
}

