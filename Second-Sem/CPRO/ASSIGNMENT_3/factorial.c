#include<stdio.h>
int main()
{
	int n,i,j;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		int factorial[1000];
		i=0;
		while(r!=0)
		{
			r=n%10;
			factorial[i]=r;
			n=n/10;
			i++;
		}

		for(j=0;j<i;j++)
		{
			for(k=1;k<n-1;k++)
			{
				m=factorial[j]*k;
				if(m<=9)
				{
					factorial[j]=factorial[j]*k;
				}


				if(m>9)
				{
					factorial[j]=m%10;




					


