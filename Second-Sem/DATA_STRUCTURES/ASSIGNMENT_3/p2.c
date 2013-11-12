#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
     int data;
     struct tree*left;
     struct tree*right;
}
node;
int arr[1000000];

node*insert(node*root,int d);
void print(node*a,int h);

int main()
{

     int d;
     char ch='a';
     while(1)
     {
	  ch='a';
	  node*root=NULL;
     while(ch!='\n')
     {
	  scanf("%d",&d);
	  root=insert(root,d);
	  scanf("%c",&ch);
     }

     print(root,-1);
     free(root);
     d=getchar();
     if(d==EOF)
	  return 0;
     else
	  ungetc(d,stdin);
     }
     return 0;
}

node*insert(node*root,int d)
{
     if(root==NULL)
     {
	  root=(node*)malloc(sizeof(node));
	  root->left=root->right=NULL;
	  root->data=d;
     }
     if(d<root->data)
	  root->left=insert(root->left,d);
     if(d>root->data)
	  root->right=insert(root->right,d);
     return root;
}

void print(node*root,int j)
{
     int i;
     if(root==NULL)
	  return;
     if(root!=NULL&&root->left==NULL&&root->right==NULL)
     {
	  j++;
	  arr[j]=root->data;
	  for(i=0;i<=j;i++)
	       printf("%d ",arr[i]);
	  printf("\n");
	  return;
     }
 
     j++;
     arr[j]=root->data;
     print(root->left,j);
     print(root->right,j);
     
}
