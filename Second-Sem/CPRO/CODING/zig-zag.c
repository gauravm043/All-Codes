#include<stdio.h>
int main()
{
     int n,t,i,j,arr[52],mem[53]={5},ans=1;
     scanf("%d",&t);
     while(t--)
     {
	  j=1;
	  ans=1;
	  scanf("%d",&n);

	  for(i=0;i<n;i++)
     {
	  scanf("%d",&arr[i]);
	  if(i>0&&(arr[i]-arr[i-1])!=0)
	  {
	       mem[j]=(arr[i]-arr[i-1]>0?1:-1);
	       j++;
	  }
     }

	  if(n==1)
	  {
	       printf("ANS-1\n");
	       continue;
	  }

     for(i=1;i<j-1;i++)
     {
	  if((mem[i+1]+mem[i]==0)&&mem[i]!=0)
	       ans++;
     }

     printf("ANS-%d\n",ans+1);
     }
     return 0;
}



