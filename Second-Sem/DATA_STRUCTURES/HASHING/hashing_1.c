#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct mm
{
     char name[100];
     struct mm*next;
}
list;


typedef struct ll
{
     int size;
     list**table;
}
node;

node ARR;

int main()
{
     int sum,j,c;
     int i,n=5;
     int index;
     char a[100];
     printf("SIZE OF HASH TABLE-->>\n");
     scanf("%d",&ARR.size);

     ARR.table=(list**)malloc(sizeof(list*)*ARR.size);

     while(1)
     {
	  sum=0;
	  scanf("%s",a);
	  for(i=0;i<strlen(a);i++)
	  {
	       sum+=a[i];
	  }
	  printf("%d\n",sum);
	  index=sum%ARR.size;
	  printf("Inserting at index %d\n",index);

	  list*new;
	  new=(list*)malloc(sizeof(list));
	  strcpy(new->name,a);
	 
	  if(ARR.table[index]==NULL)
	  {
	       printf("list at %d was null\n",index);
	       new->next=NULL;
	       ARR.table[index]=new;
	  }
	  else
	  {
	       printf("list at %d was not null\n",index);
	       new->next=ARR.table[index];
	       ARR.table[index]=new;
	  }
	  int f=1;


	  for(j=0;j<ARR.size;j++)
	  {
	       list *tmp;
	       tmp = ARR.table[j];
	       while(tmp!=NULL)
	       {
		    f=0;
		    printf("%s-->>",tmp->name);
		    tmp=tmp->next;
	       } 
	  if(f==0)
	  printf("\n");
	  f=1;
	  }
	  c=getchar();
	  if(c==EOF)
	       return 0;
	  else
	       ungetc(c,stdin);
     }

     return 0;
}
