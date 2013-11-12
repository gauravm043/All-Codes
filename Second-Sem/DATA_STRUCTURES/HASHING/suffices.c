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
     int i,n;
     int index;
     char a[100];
     printf("SIZE OF HASH TABLE-->>\n");
     scanf("%d",&ARR.size);
     printf("NUMBER OF ELEMENTS IN S:\n");
     scanf("%d",&n);

     ARR.table=(list**)malloc(sizeof(list*)*ARR.size);

     while(n--)
     {
	  sum=0;
	  scanf("%s",a);
	  for(i=0;i<strlen(a);i++)
	  {
	       sum+=a[i];
	  }
	  index=sum%ARR.size;

	  list*new;
	  new=(list*)malloc(sizeof(list));
	  strcpy(new->name,a);

	  if(ARR.table[index]==NULL)
	  {
	       new->next=NULL;
	       ARR.table[index]=new;
	  }
	  else
	  {
	       new->next=ARR.table[index];
	       ARR.table[index]=new;
	  }
     }
     int f=1;
     printf("ENTER QUERY\n");
     
     char qr[100];
     scanf("%s",qr);
     char tm[100];
     char x[2];
     int SUM=0;
     int posi;
     list * tmp;
     printf("PREFIXES ARE:-->\n");
     for(i=0;i<strlen(qr);i++)
     {
	  SUM+=qr[i];
	  posi=SUM%ARR.size;

	  x[0]=qr[i];
	  x[1]='\0';
	  strcat(tm,x);
	  tmp=ARR.table[posi];
	  while(tmp!=NULL)
	  {
	       if(strcmp(tm,tmp->name)==0)
	       {
		    printf("%s\n",tmp->name);
	       }
	       tmp=tmp->next;
	  }
     }

     return 0;
}
