#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct tree
{
     int l;
     int r;
     int data;
     struct tree*left;
     struct tree*right;
}
node;

int posi=0;
int found=0;

void healthy(node*r,int k)
{
     posi=posi+r->l+1;
     if(posi==k)
     {
	  printf("%d\n",r->data);
	  return;
     }

     if(posi<k)
	  healthy(r->right,k);
     else
     {
	  posi=posi-r->l-1;
	  healthy(r->left,k);
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
    
     if(root==NULL)
     {
	  root=(node*)malloc(sizeof(node));
	  root->left=root->right=NULL;
	  root->data=d;
	  root->l=root->r=0;
	  return root;
     }
     else if(d<root->data)
     {
	  root->l++;
	  root->left=insert(root->left,d);
     }
     else if(d>root->data)
     {
	  root->r++;
	  root->right=insert(root->right,d);
     }
     return root;
}

void search(node*root,int d)
{
     if(root==NULL)
	  return;
     if(d==root->data)
     {
	  found=1;
	  return;
     }
     if(d<root->data)
	  search(root->left,d);
     else if(d>root->data)
	  search(root->right,d);
     return;
}
int arr[10000000]={0};
int main()
{
     int i,rt;
     node*root=NULL;
     int d,k,count=0;
     char ch[20];
     while(1)
     {
	  found=0;
	  scanf("%s",ch);
	  if(!(strcmp(ch,"SetHealthy")))
	  {
	       count++;
	       scanf("%d",&d);
	       arr[d]=1;
	       root=insert(root,d);
	  }
	  else if(!(strcmp(ch,"CheckHealthy")))
	  {
	       scanf("%d",&d);
	       search(root,d);
	       if(found==1)
		    printf("YES\n");
	       else
		    printf("NO\n");
	  }
	  else if(!(strcmp(ch,"Healthy")))
	  {
	       posi=0;
	       scanf("%d",&k);
	       if(k<=count)
		    healthy(root,k);
	       else 
		    printf("NONE\n");

	  }
	  else if(!(strcmp(ch,"RottenBefore")))
	  {
	       rt=0;
	       scanf("%d",&k);
	       for(i=1;i<k;i++)
	       {
		    if(arr[i]==0)
			 rt++;
	       }
	       printf("%d\n",rt);
	  }
	  else if(!(strcmp(ch,"Quit")))
	  {
//	       free(root);
	       break;
	  }
     }
  //   print(root);
     return 0;
}
