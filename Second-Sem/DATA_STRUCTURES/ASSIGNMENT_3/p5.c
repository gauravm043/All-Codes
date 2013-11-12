#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
     int c;
     char ch[100];
     while(1)
     {
	  j=-1;
	  while(c!='\n')
	  {
	  scanf("%s",ch);
	  c=getchar();
	  node*new;
	  new=(node*)malloc(sizeof(node));
	  if(strlen(ch)>1||(strlen(ch)==1&&(ch[0]!='+'&&ch[0]!='-'&&ch[0]!='*'&&ch[0]!='/')))
	  {
	       strcpy(new->data,ch);
	       new->left=new->right=NULL;
	       j++;
	       stack[j]=new;
	  }

	  else
	  {
	       strcpy(new->data,ch);
	       new->left=stack[j-1];
	       new->right=stack[j];
	       j--;
	       stack[j]=new;
	  }

	  }
	  print(stack[0]);
     	  printf("\n");
	  c=getchar();
	  if(c==EOF)
	       return 0;
	  else
	       ungetc(c,stdin);
     }
     return 0;
}


void print(node*r)
{
     if(r==NULL)
	  return;

     printf("%s ",r->data);
     print(r->left);
     print(r->right);
}
