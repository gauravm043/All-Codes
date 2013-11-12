#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct list
{
     char data;
     struct list*left;
     struct list*right;
}
tree;
typedef struct sta
{
     tree*tr;
}
s;
s stack[100];


void EVALUATE(char a[],int y);
void print(tree*j);
char arr[1000010];
char stac[100];
int prec[8]={-1,-1,6,4,-1,4,-1,6};
int main()
{
     int t,n,place;
     int i,top,j,m;
     scanf("%d",&t);
     while(t--)
     {
	  j=0;
	  top=-1;
	  scanf("%s",arr);
	  n=strlen(arr);
	  if(n==1)
	  {
	       printf("(%s)\n",arr);
	       continue;
	  }
	  for(i=n-1;i>=0;i--)
	  {
	       place=arr[i]-40;
	       if(place>8)
	       {
		    arr[n-j-1]=arr[i];
		    j++;
	       }
	       else
	       {
		    if(top==-1)
		    {
			 top++;
			 stac[top]=arr[i]-40;
		    }
		    else if(prec[place]>=prec[stac[top]])
		    {
			 top++;
			 stac[top]=arr[i]-40;
		    }
		    else
		    {
			 while(top!=-1&&prec[place]<prec[stac[top]])
			 {
			      arr[n-j-1]=stac[top]+40;
			      j++;
			      top--;
			 }
			 top++;
			 stac[top]=arr[i]-40;
		    }
	       }
	  }

	  while(top!=-1)
	  {
	       arr[n-j-1]=stac[top]+40;
	       j++;
	       top--;
	  }
	  //for(i=0;i<n;i++)
	    //   printf("%c  ",arr[i]);


	  EVALUATE(arr,n);
     
     }
     return 0;
}


void EVALUATE(char arr[],int n)
{
     tree*new;
     int i,j=-1;
     for(i=n-1;i>=0;i--)
     {
	  if(arr[i]-40>8)
	  {
	       j++;
	       new=(tree*)malloc(sizeof(tree));
	       new->data=arr[i];
	       new->left=NULL;
	       new->right=NULL;
	       stack[j].tr=new;


	  }
	  else
	  {
	       new=(tree*)malloc(sizeof(tree));
	       new->data=arr[i];
	       new->right=stack[j-1].tr;
	       new->left=stack[j].tr;
	       j--;
	       stack[j].tr=new;


	  }


     }

     print(stack[j].tr);
     printf("\n");
}


void print(tree*h)
{
     if(h==NULL)
	  return;
     	if(h->left!=NULL&&h->right!=NULL)
        printf("(");
        print(h->left);
	printf("%c ",h->data);
        print(h->right);
     	if(h->left!=NULL&&h->right!=NULL)
	printf(")");
  
}
