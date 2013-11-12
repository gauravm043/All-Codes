#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
     int data;
     int l;
     int r;
     struct tree*left;
     struct tree*right;
}
node;
void print(node*a);
node*insert(node*a,int r);
int posi;
int main()
{
     int t,k;
     int a,b,c,n;
     scanf("%d",&t);
     while(t--)
     {
	  posi=0;
	  int d,sum=1;
	  int tr=1;
	  scanf("%d%d%d%d",&a,&b,&c,&n);
	  node*root=NULL;
	  root=insert(root,1);
	  while(n!=1)
	  {
	       posi=0;
	       k=tr%2==0?tr/2:(tr/2+1);
	       d=median(root,k);
	       d=(a*d+b*(tr+1)+c)%1000000007;
	       sum+=d;
	       root=insert(root,d);
	       n--;
	       tr++;
	  }

	  printf("%d\n",sum);

     }
     return 0;
}


node*insert(node*root,int d)
{
     if(root==NULL)
     {
	  root=(node*)malloc(sizeof(node));
	  root->data=d;
	  root->left=root->right=NULL;
	  root->l=root->r=0;
     }

     else if(d<=root->data)
     {
	  root->left=insert(root->left,d);
	  root->l++;
     }
     else if(d>root->data)
     {
	  root->right=insert(root->right,d);
	  root->r++;
     }
     
     return root;
}

int median(node*root,int k)
{
     if(root==NULL)
	  return;
     int m=9;
     posi=posi+root->l+1;
     if(posi==k)
     {
	  return root->data;
     }

     else if(posi<k)
	  m=median(root->right,k);
     else
     {
	  posi=posi-root->l-1;
	  m=median(root->left,k);
     }

     return m;
}

void print(node*root)
{
     if(root==NULL)
	  return;
     printf("%d\n",root->data);
     print(root->left);
     print(root->right);
}
