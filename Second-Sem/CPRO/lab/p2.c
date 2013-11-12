#include<stdio.h>
int main()
{
	int temp,b,t;
	scanf("%d",&t);
	while(t>0)
	{
		long long int x=0;
		int i=1;
		scanf("%d%d",&temp,&b);
		while(i<=temp)
		{
			x=x+b;
			i++;
			if(x>100000)
			x=x%100000;
			/*if(x>=100000)
			printf("%lld\n",x%100000);
			else
			printf("%lld\n",x);*/
			printf("%lld\n",x);
		}
		printf("%lld\n",x%100000);
		t--;
	}
	return 0;
}

