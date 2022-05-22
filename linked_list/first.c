#include<stdio.h>
struct linked_list
{
    int data;
    struct linked_list *next;
};

void insert_end(struct linked_list **head,int data)
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

void insert_start(struct linked_list **head,int data)
 {

   struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
   link->data = data;
   link->next = NULL;

    link->next = (*head);
    *head=link;
}

void insert_at(struct linked_list **head,int data,int key)
 {
     if(key<1)
        return;
    if((key==1)|| (*head==NULL)) insert_start(head,data);
   else
    {
   struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
   link->data = data;
   link->next = NULL;
    int temp=1;
    struct linked_list *lastNode = *head;
        while((lastNode->next != NULL)&&(temp<(key-1)))
        {
            lastNode = lastNode->next;
            temp++;
        }
        link->next=lastNode->next;
        lastNode->next = link;
    }
}

void delete_at(struct linked_list **head,int key)
{
    if(key<1)
        return;
    if((key==1))
    {
        if(*head==NULL)
            return;
        struct linked_list *temp=*head;
        *head=(*head)->next;
        free(temp);
    }
   else
    {
    int temp=1;
    struct linked_list *lastNode = *head;
    while((lastNode->next != NULL)&&(temp<(key-1)))
    {
        lastNode = lastNode->next;
        temp++;
    }
    struct linked_list *temp_node=lastNode->next;

    if((lastNode->next->next)!=NULL)
        lastNode->next = lastNode->next->next;
    else
        lastNode->next = NULL;
    free(temp_node);
    }

}

struct linked_list * create_list(int datas[],int len)
 {
    struct linked_list *head1=NULL;
    struct linked_list **head=&head1;
    for(int i=0;i<len;i++)
    {

       struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
       link->data = datas[i];
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
    return head1;
}

void printList(struct linked_list *head)
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
    struct linked_list *head=create_list(datas,(sizeof(datas)/sizeof(int)));
    printf("original list\n");
    printList(head);
    printf("list after deleting at fifth position\n");
    delete_at(&head,5);
    printList(head);
    printf("list after inserting at third position\n");
    insert_at(&head,50,3);
    printf("list after inserting at end\n");
    insert_end(&head,5);
    printList(head);
    printf("list after inserting at start\n");
    insert_start(&head,5);
    printList(head);

}
