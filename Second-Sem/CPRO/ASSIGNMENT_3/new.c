#include<stdio.h>
#include<math.h>
int main()
{
	long long int t,d,cc,n,r,sum,flag,get,k,i,j;
	scanf("%lld",&t);
	while(t!=0)
	{
		flag=1,k=0,r=-1;
		scanf("%lld",&n);
		sum=2;
		for(i=2;i<=n;i=(6*k)+r)
		{
			
			
			flag=1;
			for(j=2;j*j<=i;j++)
			{
				if(i%j==0)
				{
					flag=0;
				}
			}
			if(flag==1)
			{
			
				sum=sum+i;
			}
			

			if(r==1)
				k++;
			r=r*(-1);
		}

		if(n>=6&&n<28)
			printf("%lld\n",sum%6);
		else if(n>=28&&n<496)
			printf("%lld\n",sum%34);
		else if(n>=496&&n<8128)
			printf("%lld\n",sum%530);
		else
			printf("%lld\n",sum%8658);
                 t--;
	}
	return 0;
}






