#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
     char data[100];
     struct tree*left;
     struct tree*right;
}
node;

void print(node*a);
node*stack[100];

int main()
{
     int j=-1;
     char ch[100];
     int c;
     while(ch!='\n')
     {
	  scanf("%s",&ch);
	  c=getchar();

	  node*new;
	  new=(node*)malloc(sizeof(node));
	  if(ch-40>=8)
	  {
	       new->data=ch;
	       new->left=new->right=NULL;
	       j++;
	       stack[j]=new;
	  }

	  else
	  {
	       new->data=ch;
	       new->left=stack[j-1];
	       new->right=stack[j];
	       j--;
	       stack[j]=new;
	  }
     }


     print(stack[0]);
     printf("\n");
     return 0;
}


void print(node*r)
{
     if(r==NULL)
	  return;

     printf("%c ",r->data);
     print(r->left);
     print(r->right);
}
