#include<stdio.h>
#include<stdlib.h>
int pre[1000];
int in[1000];

typedef struct tree
{
     int data;
     struct tree*left;
     struct tree*right;
}
node;

void print(node*root)
{
     if(root->left==NULL&&root->right==NULL)
	  return;
     print(root->left);
     print(root->right);
     printf("%d   ",root->data);
}

node*make_tree(int in_l,int in_h,int pre_l,int pre_h,int c)
{
     int i,j;
    
     node*root;
     root=(node*)malloc(sizeof(node));
     int x,posi=0;
     
     x=pre[pre_l];
    
     root->data=x;
     root->left=NULL;
     root->right=NULL;
   
     if(in_l>=in_h)
	  return root;
     
     for(j=in_l;j<in_h;j++)
     {
	  if(in[j]==x)
	  {
	       posi=j;
	       break;
	  }
      }
     
     root->left=make_tree(in_l,in_l+(posi-in_l),pre_l+1,pre_l+(posi-in_l)+1,1);
     root->right=make_tree(posi+1,in_h,pre_l+(posi-in_l)+1,pre_h,0);
     return root;
}

int main()
{
     int n,i;
     node*root;
     scanf("%d",&n);
     
     for(i=0;i<n;i++)
	  scanf("%d",&in[i]);
     
     for(i=0;i<n;i++)
	  scanf("%d",&pre[i]);

     root=make_tree(0,n,0,n,0);

     print(root);
     printf("\n");
     return 0;
}
