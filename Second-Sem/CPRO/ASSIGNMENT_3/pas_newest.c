#include<stdio.h>
int main()
{
	long long int n,i,j,t;
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%lld",&n);
		long long int pascal[n][n];
		pascal[0][0]=1;
		pascal[1][0]=1;
		pascal[1][1]=1;
		for(i=2;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(j==0)
				{
				pascal[i][0]=1;
				}
				if(j==i)
				{
					pascal[i][i]=1;
				}
				if(j!=0&&(j!=i))
				{
				pascal[i][j]=pascal[i-1][j]+pascal[i-1][j-1];
				}
			
			}
		}


		for(i=0;i<n;i++)
		{
			for(j=0;j<=i;j++)
			{
				if(i!=j)
				{
				printf("%lld ",pascal[i][j]);
				}
				else
					printf("%lld",pascal[i][j]);
			}
		
			printf("\n");
		}


                



		t--;
	}
	return 0;
}




