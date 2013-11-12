#include<stdio.h>
#include<stdlib.h>

typedef struct tree
{
     int l;
     int r;
     int data;
     struct tree*left;
     struct tree*right;
}
node;

int k=0;
int posi=0;
void print(node*a);
void search(node*a);
node*insert(node*root,int d);

int main()
{
     node*root=NULL;
     int d;
     char ch='a';
     while(ch!='\n')
     {
	  scanf("%d",&d);
	  root=insert(root,d);
	  scanf("%c",&ch);
     }
     print(root);
     printf("ENTER VALUE OF K:-\n");
     scanf("%d",&k);
     search(root);
     printf("\n");

     return 0;
}
void search(node*r)
{
     posi=posi+r->l+1;
     if(posi==k)
     {
	  printf("%d  MINIMUM IS %d ",k,r->data);
	  return;
     }

     if(posi<k)
	  search(r->right);
     else
     {
	  posi=posi-r->l-1;
	  search(r->left);
     }
}




void print(node*r)
{
     if(r==NULL)
	  return;
     print(r->left);
     printf("%d    L---->%d    R---->%d\n",r->data,r->l,r->r);
     print(r->right);
}

node*insert(node*root,int d)
{
     int p;
     if(root==NULL)
     {
	  node*r;
	  r=(node*)malloc(sizeof(node));
	  r->left=r->right=NULL;
	  r->data=d;
	  return r;
     }
     if(d<root->data)
     {
	  root->l++;
	  root->left=insert(root->left,d);
     }
     if(d>root->data)
     {
	  root->r++;
	  root->right=insert(root->right,d);
     }
     return root;
}
