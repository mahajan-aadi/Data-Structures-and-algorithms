#include<stdio.h>
struct linked_list
{
    int data;
    int exponent;
    struct linked_list *next;
};

struct linked_list * create_exponent(int datas[],int len)
 {
    struct linked_list *head1=NULL;
    struct linked_list **head=&head1;
    for(int i=0;i<len;i++)
    {

       struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
       link->data = datas[i];
       link->next = NULL;
       link->exponent=0;

       if(*head==NULL) *head=link;
       else
        {
        int exp=1;
        struct linked_list *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
            exp++;
        }

        lastNode->next = link;
        link->exponent=exp;
        }
    }
    return head1;
}

void insert_data_end(struct linked_list **head,int data,int exp)
 {
   struct linked_list *link = (struct linked_list*) malloc(sizeof(struct linked_list));
   link->data = data;
   link->next = NULL;
   link->exponent=exp;
   if(*head==NULL) *head=link;
   else
    {
    struct linked_list *lastNode = *head;
        while(lastNode->next != NULL)
            lastNode = lastNode->next;
        lastNode->next = link;
    }
   }

struct linked_list * add_poly(struct linked_list **P1,struct linked_list **P2)
{
    if((*P1==NULL)&&(*P2==NULL))
        return NULL;
    else if(*P1==NULL)
        return *P2;
    else if(*P2==NULL)
        return P1;
    int temp1=0,temp2=0;
    struct linked_list *temp_node1=*P1;
    struct linked_list *temp_node2=*P2;

    int exp=0;
    struct linked_list *head1=NULL;
    struct linked_list **head=&head1;

    while((temp_node1!=NULL)||(temp_node2!=NULL))
    {
        if(temp_node1==NULL)
            temp1=0;
        else
        {
            temp1=temp_node1->data;
            temp_node1=temp_node1->next;
        }

        if(temp_node2==NULL)
            temp2=0;
        else
        {
            temp2=temp_node2->data;
            temp_node2=temp_node2->next;
        }
        insert_data_end(head,(temp1+temp2),exp);
        exp++;
    }
    return *head;
}

struct linked_list * sub_poly(struct linked_list **P1,struct linked_list **P2)
{
    if((*P1==NULL)&&(*P2==NULL))
        return NULL;
    else if(*P1==NULL)
        return *P2;
    else if(*P2==NULL)
        return P1;
    int temp1=0,temp2=0;
    struct linked_list *temp_node1=*P1;
    struct linked_list *temp_node2=*P2;

    int exp=0;
    struct linked_list *head1=NULL;
    struct linked_list **head=&head1;

    while((temp_node1!=NULL)||(temp_node2!=NULL))
    {
        if(temp_node1==NULL)
            temp1=0;
        else
        {
            temp1=temp_node1->data;
            temp_node1=temp_node1->next;
        }

        if(temp_node2==NULL)
            temp2=0;
        else
        {
            temp2=(-1)*(temp_node2->data);
            temp_node2=temp_node2->next;
        }
        insert_data_end(head,(temp1+temp2),exp);
        exp++;
    }
    return *head;
}

struct linked_list * multi_poly(struct linked_list **P1,struct linked_list **P2)
{
    if((*P1==NULL)&&(*P2==NULL))
        return NULL;
    else if(*P1==NULL)
        return *P2;
    else if(*P2==NULL)
        return P1;

    struct linked_list *temp_node1=*P1;
    struct linked_list *temp_node2=*P2;

    struct linked_list *head1=NULL;
    struct linked_list **head=&head1;

    while((temp_node1!=NULL))
    {
        temp_node2=*P2;
        if((temp_node1->data)==0)
        {
            temp_node1=temp_node1->next;
            continue;
        }
        while((temp_node2!=NULL))
        {
            if((temp_node2->data)==0)
            {
                temp_node2=temp_node2->next;
                continue;
            }
            insert_data_end(head,
                    ((temp_node1->data)*(temp_node2->data)),
                    ((temp_node1->exponent)+(temp_node2->exponent)));
            temp_node2=temp_node2->next;
        }
        temp_node1=temp_node1->next;
    }

    struct linked_list *head3=NULL;
    struct linked_list **head2=&head3;
    temp_node1=*head;

    int temp_data=0;
    int max_exp=0;
    while(temp_node1!=NULL)
    {
        if(max_exp<(temp_node1->exponent))
            max_exp=temp_node1->exponent;
        temp_node1=temp_node1->next;
    }
    temp_node1=*head;
    for(int i=0;i<=max_exp;i++)
    {
        temp_node1=*head;
        temp_data=0;
        while(temp_node1!=NULL)
        {
            if((temp_node1->exponent)==i)
            {
                temp_data+=(temp_node1->data);
            }
            temp_node1=temp_node1->next;
        }
        insert_data_end(head2,temp_data,i);
    }

    return *head2;
}
void printList(struct linked_list *head)
{
    struct linked_list *temp = head;
    while(temp != NULL)
    {
         printf("%d x_%d  + ", temp->data,temp->exponent);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int datas1[]= {0,2,4,5};
    struct linked_list *P1=create_exponent(datas1,(sizeof(datas1)/sizeof(int)));
    printf("P1:");
    printList(P1);
    int datas2[]={9,13,11};
    struct linked_list *P2=create_exponent(datas2,(sizeof(datas2)/sizeof(int)));
    printf("P2:");
    printList(P2);
    struct linked_list *add=add_poly(&P1,&P2);
    //printf("sum of two polynomials\n");
    //printList(add);
    struct linked_list *sub=sub_poly(&P2,&P1);
    //printf("subtraction of two polynomials\n");
    //printList(sub);
    struct linked_list *multi=multi_poly(&P1,&P2);
    printf("multiplication of two polynomials\n");
    printList(multi);
}
