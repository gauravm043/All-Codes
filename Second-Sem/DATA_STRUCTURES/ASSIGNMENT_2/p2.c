#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
     char data;
     struct list*next;
}
node;

node*insert(node*end,char ch)
{
     node*new;
     new=(node*)malloc(sizeof(node));
     new->data=ch;
     if(end==NULL)
     {
	  new->next=NULL;
	  return new;
     }
     else
     {
	  end->next=new;
	  new->next=NULL;
	  return end->next;
     }

}

void print(node*head,int arr[]);
int main()
{
     char ch;
     int c,cnt;
     cnt=0;
     int arr[256]={0};
     ch='a';
     node*head=NULL;
     node*end=NULL;
     while(ch!='\n')
     {
	  cnt++;
	  scanf("%c",&ch);
	  end=insert(end,ch);
	  if(cnt==1)
	  {
	       head=end;
	  }
     }

     ch='a';

     while(ch!='\n')
     {
	  scanf("%c",&ch);
	  arr[ch]=1;
     }
     print(head,arr);
     printf("\n");
     return 0;
}

void print(node*head,int arr[])
{

     while(head!=NULL)
     {
	  if(arr[head->data]!=1)
	  printf("%c",head->data);
	  head=head->next;
     }
     return;
}
