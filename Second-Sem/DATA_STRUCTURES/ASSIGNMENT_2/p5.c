#include<stdio.h>
#include<string.h>

#define OPEN arr[i]=='('||arr[i]=='['||arr[i]=='{'
#define CORRECT (((arr[i]==')'&&ch=='(')||(arr[i]=='}'&&ch=='{')||(arr[i]==']'&&ch=='[')))

char arr[10000000];
char stack[10000000];

int main()
{
     int i,t,c;
     int n,flag,top;
     char ch;
     scanf("%d",&t);
     while(t--)
     {
	  top=-1;
	  flag=1;
	  c=getchar();
	  scanf("%s",arr);
	  n=strlen(arr);
	  for(i=0;i<n;i++)
	  {
	       if(OPEN)
	       {
		    top++;
		    stack[top]=arr[i];
	       }
	       else
	       {
		    ch=stack[top];
		    top--;
		    if(!CORRECT)
		    {
			 flag=0;
			 break;
		    }
	       }
	  }

	  if(flag==1&&top==-1)
	       printf("Yes\n");
	  else
	       printf("No\n");
     }
     return 0;
}
