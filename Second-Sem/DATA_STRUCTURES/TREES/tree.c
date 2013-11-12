#include<stdio.h>
#include<stdlib.h>
typedef struct bst{
     int data;
     struct bst*left;
     struct bst*right;
     int ctr;
}bst;
bst*queue[1000];
struct bst*insert(int x,bst*root)
{
     if(root==NULL)
     {
	  bst*root=(bst*)malloc(sizeof(bst));
	  root->data=x;
	  root->ctr++;
	  root->left=NULL;
	  root->right=NULL;
	  //	  printf("insert : %d \n",x);
	  return root;
     }
     else
     {
	  if(x<root->data)
	       root->left=insert(x,root->left);
	  else if(x>root->data)
	       root->right=insert(x,root->right);
     }
     return root;
}
void print(bst*root)
{
     if(root!=NULL)
     {
	  if(root->left==NULL&&root->right==NULL)
	  {
	       printf("%d ",root->data);
	       return ;
	  }
	  print(root->left);
	  printf("%d ",root->data);
	  print(root->right);
     }
}
int minimum(bst*root)
{
     if(root!=NULL)
     {
	  if(root->left==NULL)
	  {
	       return root->data;
	  }
	  return minimum(root->left);
     }
}
struct bst*levelorder(bst*root,int start,int end)
{
     queue[start]=root;
     if(root->right!=NULL)
     {
     }
}
struct bst*delete(int x,bst*root,bst*prev)
{
     if(root!=NULL)
     {
	  if(root->data>x)
	  {
	       root->left=delete(x,root->left,root);
	       return root;
	  }
	  else if(root->data<x)
	  {
	       root->right=delete(x,root->right,root);
	       return root;
	  }
	  else
	  {
	       if(root->left==NULL&&root->right==NULL)
	       {
		    free(root);
		    return NULL;
	       }
	       else if(root->left==NULL)
	       {
		    return root->right;
	       }
	       else if(root->right==NULL)
	       {
		    return root->left;
	       }
	       else
	       {
		    int r;
		    r=minimum(root->right);
		    root->right=delete(r,root->right,root);
		    root->data=r;
	       }
	       return root;
	  }
     }
}
int main()
{
     char c;
     int x;
     bst*root=NULL;
     bst*prev=NULL;
     while((c=getchar())!='Q')
     {
	  if(c=='I')
	  {
	       scanf("%d",&x);
	       root=insert(x,root);
	  }
	  else if(c=='P')
	  {
	       print(root);
	       printf("\n");
	  }
	  else if(c=='M')
	       x=minimum(root);
	  else if(c=='R')
	  {
	       scanf("%d",&x);
	       root=delete(x,root,prev);
	  }
	  else if(c=='L')
	  {
	       levelorder(root);
	       printf("\n");
	  }
     }
     return 0;
}
