#include<stdio.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node * insert(struct node * root,int data)
{
    struct node * temp=root;
    while(1)
    {
        if(data<(temp->data))
        {
            if((temp->left)==NULL)
            {
                struct node *temp_node=(struct node *)malloc(sizeof(struct node));
                temp_node->left=temp_node->right=NULL;
                (temp->left)=temp_node;
                temp_node->data=data;
                break;
            }
            else temp=(temp->left);
        }
        else
        {
            if((temp->right)==NULL)
            {
                struct node *temp_node=(struct node *)malloc(sizeof(struct node));
                temp_node->right=temp_node->left=NULL;
                (temp->right)=temp_node;
                temp_node->data=data;
                break;
            }
            else temp=(temp->right);
        }
    }
    return root;
}
void create_bst(struct node* root,int datas[],int size)
{
    for(int i=0;i<size;i++)
    {
        int data=datas[i];
        insert(root,data);
    }
}
void print_tree(struct node * root,int height_tree)
{
    if(root==NULL)
        return;

    printf("              ");
    for(int i=0;i<height_tree;i++)
    {
        for(int j=i;j<height_tree;j++)
            printf("      ");
        print_level(root,i);
        printf("\n\n");
    }
}
void print_level(struct node * root,int level)
{
    if(root==NULL)
        return;
    if(level==0)
        printf("%d",root->data);

    printf(" ");
    print_level(root->left,level-1);
    printf("      ");
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
int main()
{
    int datas[]={21,45,65,87,20,32,64,15,48,123};
    struct node *root=(struct node *)malloc(sizeof(struct node));
    root->left=root->right=NULL;
    root->data=50;
    create_bst(root,datas,sizeof(datas)/sizeof(datas[0]));
    print_tree(root,height(root));
}
