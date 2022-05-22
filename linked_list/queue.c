#include<stdio.h>
struct linked_list
{
    int data;
    struct linked_list *next;
};
int dequeue(struct linked_list **head)
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
void enqueue(struct linked_list **head,int data)
 {

   struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
   link->data = data;
   link->next = NULL;

    link->next = (*head);
    *head=link;
}
void printQueue(struct linked_list *head)
{
    struct linked_list *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int datas[]= {10,64,45,98,13,98,565,32,11,101};
    struct linked_list *head=NULL;

    printf("After enqueue operations");
    for(int i=0;i<10;i++)
        enqueue(&head,datas[i]);
    printQueue(head);

    printf("After a dequeue operations");
    dequeue(&head);
    printQueue(head);
}
