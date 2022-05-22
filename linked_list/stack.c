#include<stdio.h>
struct linked_list
{
    int data;
    struct linked_list *next;
};
void push(struct linked_list **head,int data)
 {

   struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
   link->data = data;
   link->next = NULL;

   if(*head==NULL) *head=link;
   else
    {
    struct linked_list *lastNode = *head;
        while(lastNode->next != NULL)
            lastNode = lastNode->next;
        lastNode->next = link;
    }
}
void printStack(struct linked_list *head)
{
    struct linked_list *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int pop(struct linked_list **head)
{
    if(*head==NULL)
        return -1;
    struct linked_list *lastNode = *head;
    while((lastNode->next->next != NULL))
    {
        lastNode = lastNode->next;
    }
    struct linked_list *temp_node=lastNode->next;
    lastNode->next = NULL;
    free(temp_node);
}
int main()
{
    int datas[]= {10,64,45,98,13,98,565,32,11,101};
    struct linked_list *head=NULL;

    for(int i=0;i<10;i++)
        push(&head,datas[i]);
    printf("After push operations");
    printStack(head);

    pop(&head);
    printf("After a pop operations");
    printStack(head);
}
