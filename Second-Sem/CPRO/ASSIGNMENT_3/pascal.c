#include<stdio.h>
long long int factorial(long long int n);
int main()
{
	long long int n,num,t;
	int l,i,k,j;
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%d",&l);
		for(i=0;i<l;i++)
		{
			for(j=0;j<=i;j++)
			{
				num=factorial(i)/(factorial(j)*factorial(i-j));
			        printf("%lld ",num);
			}
		printf("\n");
		}
		t--;
	}
	return 0;
}
long long int factorial(long long int n)
{
	long long int ans;
	int i;
	ans=1;
	for(i=1;i<=n;i++)
	{
		ans=i*ans;
	}
	return (ans);
}





		

