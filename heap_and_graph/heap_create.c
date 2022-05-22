#include<stdio.h>
#include<math.h>
struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void print_heap(struct node * root,int height_heap)
{
    if(root==NULL)
        return;

    printf("           ");
    for(int i=0;i<height_heap;i++)
    {
        for(int j=i;j<height_heap;j++)
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
        printf("%d",root->data);

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

struct node * create_node(int data)
{
        struct node *temp=(struct node *)malloc(sizeof(struct node));
        temp->data=data;
        temp->left=temp->right=NULL;
        return temp;
}
struct node * create_heap(struct node *root,int datas[],int n,int size)
{
    if(n<size)
    {
        struct node *temp=create_node(datas[n]);
        root=temp;
        root->left=create_heap(root->left,datas,2*n+1,size);
        root->right=create_heap(root->right,datas,2*n+2,size);
    }
    return root;
}
int main()
{
    int datas[]={50,21,45,65,87,20,32,64,15,48,123};
    struct node *root=NULL;
    root=create_heap(root,datas,0,sizeof(datas)/sizeof(datas[0]));
    print_heap(root,height(root));
}
