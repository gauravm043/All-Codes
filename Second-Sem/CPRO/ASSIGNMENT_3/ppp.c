#include<stdio.h>
int main()
{       long long int max=1000000;
	long long int n,i,p=0,j,prime[max]={0};
	prime[1]=prime[0]=1;
	for(i=2;i<max;i=i+1)
	{
		while(prime[i]==1&&i<max)
		{
			++i;
		}

		prime[p]=i;

		for(j=i*i;j<max;j=j+i)
		{
			prime[i]=1;
		}

		p++;

		printf("%lld\n",i);
	}
       return 0;
}

	



