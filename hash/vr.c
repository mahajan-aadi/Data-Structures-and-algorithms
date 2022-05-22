#include<stdio.h>
#include<math.h>
struct node
{
int data;
struct node*left;
struct node*right;
};
void printheap(struct node*root,int heightheap)
{
if(root==NULL)
return ;
printf("      ");
for(int i=0;i<heightheap;i++)
{
for(int j=i;j<heightheap;j++)
printf(" ");
printlevel(root,i);
printf("\n\n");
}
}
void printlevel(struct node*root,int level)
{
if(root==NULL)
return ;
if(level==0)
printf("%d",root->data);
printf(" ");
printlevel(root->left,level-1);
printf("    ");
printlevel(root->right,level-1);
printf(" ");
}
int height(struct node*root)
{
if(root==NULL)
return 0;
int lheight=height(root->left);
int rheight=height(root->right);
return rheight>lheight?(1+rheight):(1+lheight);
}
struct node*createnode(int data)
{
struct node*temp=(struct node*)malloc(sizeof(struct node));
temp->data=data;
temp->left=temp->right=NULL;
return temp;
}
struct node*createheap(struct node*root,int datas[],int n,int size)
{
if(n<size)
{
struct node*temp=createnode(datas[n]);
root=temp;
root->left=createheap(root->left,datas,2*n+1,size);
root->right=createheap(root->right,datas,2*n+2,size);
}
return root;
}
int main()
{
int datas[]={50,21,45,65,87,20,32,64,15,48,123};
struct node*root=NULL;
root=createheap(root,datas,0,sizeof(datas)/sizeof(datas[0]));
printheap(root,height(root));
}
