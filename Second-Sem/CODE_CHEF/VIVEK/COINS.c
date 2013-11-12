#include<stdio.h>

int solve(int n)
{
     int sum,coin1,coin2,coin3;
     int ans;
     if(n<=3)
	  return n;
     coin1=n/2;
     coin2=n/3;
     coin3=n/4;
     sum=coin1+coin2+coin3;
     sum=sum-coin1;
     ans=solve(coin1);
     if(ans<coin1)
	  ans=coin1;
     sum+=ans;
     sum=sum-coin2;
     ans=solve(coin2);
     if(ans<coin2)
	  ans=coin2;
     sum+=ans;
     sum=sum-coin3;
     ans=solve(coin3);
     if(ans<coin3)
	  ans=coin3;
     sum+=ans;
     return sum;

}


int main()
{
     int test;
     int n,ans;
     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d",&n);
	  ans=n;
	  ans=solve(n);
	  if(ans==0)
	       ans=n;
	  printf("%d\n",ans);
     }
     return 0;
}
