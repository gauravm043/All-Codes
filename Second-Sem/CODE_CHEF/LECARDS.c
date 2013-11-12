#include<stdio.h>
#include<math.h>
long long int power(int n)
{
     int i;
     long long int pro=1;
     for(i=1;i<n;i++)
     {
	  pro=pro*2;
	  pro=pro%1000000007;
     }
     return pro;
}

int main()
{
     int t,n,pro,temp;
     int r,ans,term,i;
     scanf("%d",&t);
     while(t--)
     {
	  pro=1;
	  scanf("%d",&n);
	  //for(i=0;i<n;i++)
	    //   scanf("%d",&temp);
	  if(n%2!=0)
	  {
	       printf("%lld\n",(power(n)%1000000007));
	 
	  }

	  else
	  {

	  r=0;
	  while(r!=n/2)
	  {
	       term=(n-r)/(n/2-r);
	       pro=((pro)%1000000007)*(term)%1000000007;
	       r=r+1;
	  }

	  pro=pro%1000000007;

	  ans=((power(n)-pro)/2)%1000000007;

	  printf("%d\n",ans);
	  }
     }

     return 0;
}
