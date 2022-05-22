#include<stdio.h>

///stack array
char arr[100];
int top=-1;
int n=100;
char pop()
{
    if(top>(-1))
    {
        top--;
        return arr[top+1];
    }
    else
    {
        printf("stack underflow");
        return -1;
    }
}
void push(char data)
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
char peek()
{
    if(top>-1)
        return arr[top];
    else
        return -1;
}

///node
struct node
{
    char data;
    struct node* left;
    struct node* right;
};
///tree printing
void print_tree(struct node * root,int height_tree)
{
    if(root==NULL)
        return;

    printf("           ");
    for(int i=0;i<height_tree;i++)
    {
        for(int j=i;j<height_tree;j++)
            printf("       ");
        print_level(root,i);
        printf("\n\n");
    }
}
void print_level(struct node * root,int level)
{
    if(root==NULL)
        return;
    if(level==0)
        printf("%c",root->data);

    printf("  ");
    print_level(root->left,level-1);
    printf("  ");
    print_level(root->right,level-1);
    printf("  ");
}
int height(struct node * root)
{
    if(root==NULL)
        return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    return rheight>lheight?(1+rheight):(1+lheight);
}
///stack for node

struct node * arr_node[15]={NULL};
int top_node=-1;
int n1=15;
struct node * pop_node()
{
    if(top_node>(-1))
    {
        top_node--;
        return (arr_node[top_node+1]);
    }
    else
    {
        printf("stack underflow");
    }
}
void push_node(struct node * data)
{
    if(top_node<(n1-1))
    {
        arr_node[++top_node]=data;
    }
    else
    {
        printf("stack overflow");
    }
}
///base code

void inorder(struct node * root)
{
    if(root==NULL)  return;
    inorder(root->left);
    printf("%c ",root->data);
    inorder(root->right);
}
void postorder(struct node * root)
{
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    printf("%c ",root->data);
}

int priority(char symbol)
{
    if(symbol=='(')
        return 0;
    if(symbol=='^')
       return 1;
    if(symbol=='*' || symbol=='/')
       return 2;
    if(symbol=='+' || symbol=='-')
       return 3;
    return 100;

}
char *postfix_expression(char expression[],int size)
{
    char *ptr=expression;
    static char exp[100]={0};
    int index=0;
    while(*ptr!=NULL)
    {
        if(isdigit(*ptr))
        {
            exp[index++]=*ptr;
        }
        else if(priority(*ptr)<4)
        {
            int i=priority(*ptr);
            int p=priority(peek());

            if(i==0)
                push(*ptr);
            else if(i<p)
                push(*ptr);
            else if(i>p)
            {
                while((peek()!= -1) && (p!=i) && (peek()!='('))
                {
                    exp[index++]=pop();
                    p=priority(peek());
                }
                push(*ptr);
            }
            else
            {
                if(i==1)
                    push(*ptr);
                else
                {
                    exp[index++]=pop();
                    push(*ptr);
                }
            }
        }
        else if(*ptr==')')
        {
            while(peek()!='(')
            {
                exp[index++]=pop();
            }
            pop();
        }
        ptr++;
    }
    while(peek()!=-1)
    {
        exp[index++]=pop();
    }

    return exp;
}
struct node * create_tree(char expression[],int size)
{
    if(size<3)
        return NULL;
    char *postfixexpression=postfix_expression(expression,size);

    char *ptr=postfixexpression;

    while(*ptr!=NULL)
    {
        if(isdigit(*ptr))
        {
            struct node * i=(struct node *)malloc(sizeof(struct node));
            i->data=*ptr;
            i->left=NULL;
            i->right=NULL;
            push_node(i);
        }
        else
        {
            struct node * i=(struct node *)malloc(sizeof(struct node));
            i->data=*ptr;
            i->right=pop_node();
            i->left=pop_node();
            push_node(i);
        }
        ptr++;
    }
    return pop_node();
}

int main()
{
    char expression[]={"((4+8)*(6-5))/((3-2)*(2+2))"};
    int size=sizeof(expression)/sizeof(expression[0]);
    struct node * root = create_tree(expression,size);

    printf("Expression Tree: \n");
    print_tree(root,height(root));

    printf("\nPostfix expression:\n");
    postorder(root);
    printf("\nInfix expression:\n");
    inorder(root);
}
