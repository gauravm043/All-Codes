//------------------------------------------------------------------------------------------------------------------------//

/*                                           CODE DEVELOPED FOR AN AVL TREE

					     BY-GAURAV MISHRA
					     IIIT-HYDERABAD

 */

//-----------------------------------------------------------------------------------------------------------------------//




#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
     int h;
     int data;
     struct tree*left;
     struct tree*right;
}
node;

int max(node*a);
node * insert(node*a,int d);
void print(node*w);   

int main()
{
     int d;
     node*root=NULL;
     int ch=1;
     int q;
     scanf("%d",&ch);
     while(ch--)
     {
	  scanf("%d",&d);
	  root=insert(root,d);
     }
     scanf("%d",&q);
     while(q--)
     {
	  scanf("%d",&d);
	  search(d);
     }
   
     return 0;

}
node*LL(node*r)
{
     node*x;
     x=r->left;
     r->left=x->right;
     x->right=r;
     r->h=max(r)+1;
     x->h=max(x)+1;
     return x;
}
node*RR(node*r)
{
     node*x;
     x=r->right;
     r->right=x->left;
     x->left=r;
     r->h=max(r)+1;
     x->h=max(x)+1;
     return x;
}
node*RL(node*r)
{
     r->right=LL(r->right);
     r=RR(r);
     return r;
}
node*LR(node*r)
{
     r->left=RR(r->left);
     r=LL(r);
     return r;
}


int max(node*a)
{
     if(a->left==NULL&&a->right==NULL)
	  return -1;
     if(a->left==NULL)
	  return a->right->h;
     if(a->right==NULL)
	  return a->left->h;
     else
     {
	  if(a->left->h>a->right->h)
	       return a->left->h;
	  else
	       return a->right->h;
     }
}

void print(node*root)
{
     if(root==NULL)
	  return;
     printf("%d--------->%d\n",root->data,root->h);
     print(root->left);
     print(root->right);
}
node*insert(node*root,int d)
{
     int m;
     if(root==NULL)
     {
	  node*a;
	  a=(node*)malloc(sizeof(node));
	  a->data=d;
	  a->left=a->right=NULL;
	  a->h=0;
	  return a;
     }
     if(d>root->data)
     { 
	  root->right=insert(root->right,d);
	  root->h=max(root)+1;
	  if(root->left!=NULL)
	       m=root->left->h;
	  else
	       m=-1;
	  if(root->right->h-m>1)
	  {
	       if(d>root->right->data)
		    root=RR(root);
	       else
		    root=RL(root);
	  }

     }
     if(d<root->data)
     {
	  root->left=insert(root->left,d);
	  root->h=max(root)+1;
	  if(root->right!=NULL)
	       m=root->right->h;
	  else
	       m=-1;
	  if(root->left->h-m>1)
	  {
	       if(d<root->left->data)
		    root=LL(root);
	       else
		    root=LR(root);
	  }
     }
     return root;
}

void search(int d);
