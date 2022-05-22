/*#include<stdio.h>

int arr[10];
int top=-1;
int n=10;

int main()
{
    push(3);
    push(4);
    push(8);
    push(12);
    print_array();
    pop();
    pop();
    print_array();
}
void pop()
{
    if(top>(-1))
    {
        top--;
    }
    else
    {
        printf("stack underflow");
    }
}
void push(int data)
{
    if(top<(n-1))
    {
        arr[++top]=data;
    }
    else
    {
        printf("stack overflow");
    }
}
void print_array()
{
    for(int i=0;i<=top;i++)
    {
        int temp=arr[i];
        printf("%d,",temp);
    }
     printf("\n");
}

*/
