#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
     int data;
     struct tree*left;
     struct tree*right;
}
node;

node*queue[1000];

int i=0;
int j=0;
int n=0;

node*insert(node*root,int d)
{
     if(root==NULL)
     {
	  node*r;
	  r=(node*)malloc(sizeof(node));
	  r->data=d;
	  r->left=r->right=NULL;
	  return r;
     }

     if(d<root->data)
	  root->left=insert(root->left,d);
     if(d>root->data)
	  root->right=insert(root->right,d);
     return root;
}

void print(node*r)
{
     if(i==n)
	  return;

     printf("%d ",queue[i]->data);
     if(queue[i]->left!=NULL)
	  queue[++j]=queue[i]->left;
     if(queue[i]->right!=NULL)
	  queue[++j]=queue[i]->right;
     ++i;
     print(queue[i]);
}


int main()
{
     node*root=NULL;
     char ch='A';
     int d;
     while(ch!='\n')
     {
	  ++n;
	  scanf("%d",&d);
	  root=insert(root,d);
	  scanf("%c",&ch);
     }
     queue[0]=root;
     print(root);
     printf("\n");
     return 0;
}
