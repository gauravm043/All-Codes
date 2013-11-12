#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
     int data;
     int cnt;
     struct tree*left;
     struct tree*right;
}
node;

node*insert(node*root,int d)
{

     if(root==NULL)
     {
	  node*rootm;
	  rootm=(node*)malloc(sizeof(node));

	  rootm->data=d;
	  rootm->left=NULL;
	  rootm->right=NULL;
	  return rootm;
     }
     else
     {
	  if(root->data<d)
	       root->right=insert(root->right,d);
	  if(root->data>d)
	       root->left=insert(root->left,d);
	  else if(root->data==d)
	       root->cnt++;
	  return root;
     }
}

void print(node*root)
{
     if(root==NULL)
	  return;
     print(root->left);
     printf("%d  ",root->data);
     print(root->right);
}

int find(node*root,int d)
{
     int check=0;
     if(root==NULL)
	  return;
     if(root->data==d)
     {
	  printf("ELEMENT FOUND WITH FRE --> %d\n",root->cnt+1);
	  check=1;
	  return check;
     }
     if(d<root->data)
     find(root->left,d);
     else
     find(root->right,d);
}

int min(node*root)
{
     int a;

     if(root->left==NULL)
     {
	  return root->data;
     }

     a=min(root->left);
     return a;
}

node* delete(node*root,int d)
{
     if(root==NULL)
	  return;

    if(root->data==d)
    {
	 if(root->cnt>0)
	      root->cnt--;
	 else
	 {
	      /* ELEMENT WITH NO CHILD */

	      if(root->left==NULL&&root->right==NULL)
	      {
		   free(root);
		   return NULL;
	      }

	      /* ELEMENT WITH ONE CHILD */

	      if(root->right==NULL)
	      {
		   return root->left;
		   free(root);
	      }
	      if(root->left==NULL)
	      {
		   return root->right;
		   free(root);
	      }

	      /* ELEMENTS WITH TWO CHILDRENS BY REPLACING IT WITH MINIMUM VALUE IN THE RIGHT SUBTREE */

	      int p;
	      p=min(root->right);
	      root->data=p;
	      root->right=delete(root->right,p);
	      return root;


	 }
    }

    if(d<root->data)
	 root->left=delete(root->left,d);
    else if(d>root->data)
	 root->right=delete(root->right,d);
    return root;
}

int main()
{
     int check=0;
     int d,m;
     char ch;
     node*root;
     root=NULL;
     while(1)
     {
	  check=0;
	  scanf("%c",&ch);
	  if(ch!='\n')
	  {
	       switch(ch)
	       {
		    case 'I':
			 scanf("%d",&d);
			 root=insert(root,d);
			 break;
		    case 'P':
			 print(root);
			 printf("\n");
			 break;
		    case 'F':
			 scanf("%d",&d);
			 check=find(root,d);
			 if(check==0)
			      printf("ELEMENT NOT FOUND\n");
			 break;
		    case 'M':
			 m=min(root);
			 printf("MINIMUM-->>%d\n",m);
			 break;
		    case 'D':
			 scanf("%d",&d);
			 delete(root,d);
			 break;

		    case 'Q':
			 return 0;


	       }
	  }

     }
}

