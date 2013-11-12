#include<stdio.h>
int arr[500000]={0};
int fre[500000]={0};
int stack[500000]={0};
int main()
{
     int i,t;
     long long int ans;
     int n,top;
     scanf("%d",&t);
     while(t--)
     {
	  ans=0;
	  top=-1;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	  {
	       scanf("%d",&arr[i]);
	       fre[i]=0;
	  }

	  /* EVALUATING*/

	  for(i=0;i<n;i++)
	  {
	       top++;
	       stack[top]=arr[i];
	       fre[top]=1;
	       while(top>0&&stack[top-1]<=stack[top])
	       {
		    if(stack[top]==stack[top-1])
		    {
			 ans+=fre[top-1];
			 fre[top-1]++;
			 top--;
		    }
		    else
		    {
			 ans+=fre[top-1];
			 stack[top-1]=stack[top];
			 fre[top-1]=fre[top];
			 top--;
		    }
	       }
	       if(top>=1)
		    ans++;
	 }
	  printf("%lld\n",ans);
     }
     return 0;
}
