#include<stdio.h>
#include<math.h>
int ele[6]={2,3,5,7,11,61};

int modpow(a,b,p)
{
     if(b==0)
	  return 1;

     int ans=1;
     while (b!=0)
     {
	  if (b%2 == 1)
	       ans = (ans*a)%p;

	  a = (a*a)%p;
	  b=b/2;

     }

     return ans ;
}





int is_prime(int n)
{
     int p=n-1;
     int p2=0;

     while (p%2==0)
     {
	  p=p/2;
	  p2=p2+1;
     }

     int kk=0,j;

     while(kk!=6)
     {
	  if (ele[kk]>n-2)
	       break;
	  int rem=modpow(ele[kk],p,n);
	  int flag=0;
	  if (rem==1 || rem==n-1)
	  {
	       kk++;
	       continue;
	  }

  for(j=0;j<	=p2-1;j++)
	  {

	       rem=(rem*rem)%n;
	       if (rem==1)
		    return 0;
	       if (rem==n-1)
	       {
		    flag=1;
		    break;
	       }
	  }
	  if (flag==0)
	       return 0;
	  kk++;
     }
     return 1;
}




void generate(int m,int n)
{
     int i=m,ans;
     for(i=m;i<=n;i++)
     {
	  ans=is_prime(i);
	  if(ans==1)
	       printf("%d\n",i);
     }
}



int main()
{
     int test;
     int m,n;
     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d%d",&m,&n);
	  if(m%2==0&&m!=2)
	       m=m+1;
	  if(m==1)
	       m=2;
	  generate(m,n);
     }
     return 0;
}
