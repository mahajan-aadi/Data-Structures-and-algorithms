#include<stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
void preorder(struct node * root)
{
    if(root==NULL)  return;
    printf("%d->",root->data);
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct node * root)
{
    if(root==NULL)  return;
    inorder(root->left);
    printf("%d->",root->data);
    inorder(root->right);
}
void postorder(struct node * root)
{
    if(root==NULL)  return;
    postorder(root->left);
    postorder(root->right);
    printf("%d->",root->data);
}
void print_tree(struct node * root,int height_tree)
{
    if(root==NULL)
        return;

    printf("          ");
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
    {
        printf("    ");
        return;
    }
    if(level==0)
        printf("%d",root->data);

    printf("  ");
    print_level(root->left,level-1);
    printf(" ");
    print_level(root->right,level-1);
    printf(" ");
}
int height(struct node * root)
{
    if(root==NULL)
        return 0;
    int lheight=height(root->left);
    int rheight=height(root->right);
    return rheight>lheight?(1+rheight):(1+lheight);
}
void main()
{
     struct node *root=(struct node *)malloc(sizeof(struct node));

    struct node *node1 =(struct node *)malloc(sizeof(struct node));
    struct node *node2 =(struct node *)malloc(sizeof(struct node));
    struct node *node3 =(struct node *)malloc(sizeof(struct node));
    struct node *node4 =(struct node *)malloc(sizeof(struct node));
    struct node *node5 =(struct node *)malloc(sizeof(struct node));
    struct node *node6 =(struct node *)malloc(sizeof(struct node));
    struct node *node7 =(struct node *)malloc(sizeof(struct node));
    struct node *node8 =(struct node *)malloc(sizeof(struct node));
    struct node *node9 =(struct node *)malloc(sizeof(struct node));

    root->data=50;      root->left=node1;      root->right=node2;
    node1->data=17;     node1->left=node3;     node1->right=node4;
    node2->data=72;     node2->left=node5;     node2->right=node6;
    node3->data=12;     node3->left=node7;     node3->right=node8;
    node4->data=23;     node4->left=NULL;      node4->right=NULL;
    node5->data=54;     node5->left=NULL;      node5->right=node9;
    node6->data=76;     node6->left=NULL;      node6->right=NULL;
    node7->data=9;      node7->left=NULL;      node7->right=NULL;
    node8->data=14;     node8->left=NULL;      node8->right=NULL;
    node9->data=67;     node9->left=NULL;      node9->right=NULL;

    printf("tree-->\n");
    print_tree(root,height(root));
    printf("\n preorder-->\n");
    preorder(root);
    printf("\n inorder-->\n");
    inorder(root);
    printf("\n postorder-->\n");
    postorder(root);
}
