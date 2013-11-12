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
     int l;
     int r;
     int h;
     int data;
     struct tree*left;
     struct tree*right;
}
node;

int posi=0;
int max(node*a);
node * insert(node*a,int d);
void print(node*w);   

int main()
{
     int t;
     long long int a,b,c;
     int n;
     scanf("%d",&t);
     while(t--)
     {
	  int d;
	  long long int sum=1;
	  int tr=1;
	  int k;
	  posi=0;
	  scanf("%lld%lld%lld%d",&a,&b,&c,&n);
	  node*root=NULL;
	  root=insert(root,1);
	  while(n!=1)
	  {    posi=0;
	       k=tr%2==0?tr/2:(tr/2+1);
	       //printf(" TREE====>>>>\n");
	       //print(root);
	      // printf("median\n");
	       d=median(root,k);
	       //printf("%d\n\n\n",d);
	       d=(a*d+b*(tr+1)+c)%1000000007;
	       sum+=d;
	       root=insert(root,d);
	       n--;
	       tr++;
	  }
	//  print(root);
	  if(sum==1)
	       printf("0\n");
	  else
	  printf("%lld\n",sum);
     }
}
node*LL(node*r)
{
     node*x;
     x=r->left;
     r->left=x->right;
     r->l=x->r;
     x->right=r;
     x->r=r->l+r->r+1;
     r->h=max(r)+1;
     x->h=max(x)+1;
     return x;
}
node*RR(node*r)
{
     node*x;
     x=r->right;
     r->r=x->l;
     r->right=x->left;
     x->left=r;
     x->l=r->l+r->r+1;
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
     print(root->left);
     printf("%d--------->%d\n",root->data,root->h);
     print(root->right);
}
node*insert(node*root,int d)
{
     int m;
     if(root==NULL)
     {
	  root=(node*)malloc(sizeof(node));
	  root->data=d;
	  root->left=root->right=NULL;
	  root->h=root->l=root->r=0;
     }

     else if(d>root->data)
     { 
	  root->right=insert(root->right,d);
	  root->r++;
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
     else if(d<=root->data)
     {
	  root->left=insert(root->left,d);
	  root->l++;
	  root->h=max(root)+1;
	  if(root->right!=NULL)
	       m=root->right->h;
	  else
	       m=-1;
	  if(root->left->h-m>1)
	  {
	       if(d<=root->left->data)
		    root=LL(root);
	       else
		    root=LR(root);
	  }
	  root->l++;
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
