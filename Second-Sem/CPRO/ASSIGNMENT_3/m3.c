#include<stdio.h>
int main()
{
	long long int t,k;                             
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%lld",&k);
		for(i=1;i<=k;i++);
		{
			scanf("%lld %lld",&p,&q);
			long long int A[p][q];
			if(i==1)
				g1=p;
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
				{
					scanf("%lld",&A[i][j]);
				}
			}
                       
			if(i==1)
			{
				scanf("%lld %lld",&m,&n);
				long long int B[m][n];
				g2=n;
				for(i=0;i<m;i++)
			{
				for(j=0;j<n;j++)
				{
					scanf("%lld",&B[i][j]);
				}
			}
				if(m==q)
				{
					long long int C[g1][g2];
					for(i=0;i<p;i++)
					{
						for(i=0;i<n;i++)
						{
						     for(k=0;k<m;k++)
						     {
							     C[i][j]=A[i][k]*B[k][j];
						     }
						}
					}
				}
			}
			else
			{
				long long int O[g1][g2]
				if(q==g1)
				{
					for(i=0;i<p;i++)
					{
						for(j=0;j<g2;j++)
						{
							for(k=0;k<g1;k++)
							{
								O[i][j]=C[i][k]*B[k][j];
							}
						}
					}
				}
			}
		}








							






