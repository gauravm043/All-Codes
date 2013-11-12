#include<stdio.h>
#include<string.h>
typedef struct list
{
     char data[100001];
}
node;
node final[100];

char arr[100001];
char out[100001];
char stack[110001];
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
		    out[j]=arr[i];
		    j++;
	       }
	       else
	       {
		    if(top==-1)
		    {
			 top++;
			 stack[top]=arr[i]-40;
		    }
		    else if(prec[place]>=prec[stack[top]])
		    {
			 top++;
			 stack[top]=arr[i]-40;
		    }
		    else
		    {
			 while(top!=-1&&prec[place]<prec[stack[top]])
			 {
			      out[j]=stack[top]+40;
			      j++;
			      top--;
			 }
			 top++;
			 stack[top]=arr[i]-40;
		    }
	       }
	  }

	  while(top!=-1)
	  {
	       out[j]=stack[top]+40;
	       j++;
	       top--;
	  }

	  int k=0,tmp;
	  j=-1;

	  for(i=0;i<n;i++)
	  {

	       if(out[i]-40>8)
	       {
		    j++;
		    final[j].data[0]=out[i];
		    final[j].data[1]='\0';
	       }

	       else
	       {
		    int p=0;
		    stack[p]='(';
		    stack[p+1]='\0';
		  
		    strcat(stack,final[j].data);
		    tmp=strlen(stack);
		    stack[tmp]=out[i];
		    stack[tmp+1]='\0';
		    strcat(stack,final[j-1].data);
		    strcat(stack,")");
		    j--;
		   strcpy(final[j].data,stack);
	       }


	  }

	  for(i=0;i<=j;i++)
	  {
	       printf("%s",final[i].data);
	  }

	  printf("\n");
     }
     return 0;
}
