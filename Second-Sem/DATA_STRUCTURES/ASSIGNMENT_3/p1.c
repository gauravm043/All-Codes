#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
     int data;
     int h;
     struct tree*left;
     struct tree*right;
}
node;

void fr(node*root)
{
     if(root==NULL)
	  return;
     fr(root->left);
     fr(root->right);
     free(root);
}
int H(node*a);
long long int maxi=0;
node*insert(node*root,int d);

int main()
{
     int d,c;
     char ch='a';
     while(1)
     {
	  maxi=0;
	  ch='a';
	  node*root=NULL;
     while(ch!='\n')
     {
	  scanf("%d",&d);
	  root=insert(root,d);
	  scanf("%c",&ch);
     }

     printf("%d\n",root->h);
     printf("%lld\n",maxi);
     fr(root);
     c=getchar();
	  if(c==EOF)
	       return 0;
	  else
	       ungetc(c,stdin);
     }
}


int H(node*r)
{
     if(r==NULL)
	  return -1;
     else
	  return r->h;
}

node*insert(node*root,int d)
{
    long long int p;
     if(root==NULL)
     {
	  root=(node *)malloc(sizeof(node));
	  root->left=root->right=NULL;
	  root->data=d;
	  root->h=0;
     }
     else if(d<root->data)
     {
	  root->left=insert(root->left,d);
	  root->h=max(root)+1;
     }
     else if(d>root->data)
     {
	  root->right=insert(root->right,d);
	  root->h=max(root)+1;
     }
     p=H(root->left)+H(root->right)+3;
     if(maxi<=p)
	  maxi=p;
     return root;
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
