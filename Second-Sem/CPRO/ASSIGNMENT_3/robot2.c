#include<stdio.h>
int main()
{
	long long int X,W,z1,z2,z3,z4,pro;
	int n,m,s,t,i,j,C2,R2,c,r,M,N,C,R;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d %d %d",&n,&m,&s);
		N=n,M=m;
		long long int robo[n][m];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
				scanf("%lld",&robo[i][j]);
		}


		X=0,W=0,z1=0,z2=1,z3=0,z4=0,pro=1;
		while(s!=0)
		{
		

		C=M-1;
		for(i=z3;i<=(N-1);i++)
		{
		
			if(s>0)
			{
				pro=(pro*robo[i][C])%1000000007;
				s--;
			}
			else
				break;
		}



		R=N-1;
		for(j=(M-2);j>=z1;j--)
		{
			if(s>0)
			{
				pro=(pro*robo[R][j])%1000000007;
				s--;
			}
			else
				break;
		}




		C2=X;
		for(i=(N-2);i>=z4;i--)
		{
			if(s>0)
			{
			pro=(pro*robo[i][C2])%1000000007;
			s--;
			}
			else
				break;
		}


		R2=W;
		for(j=z2;j<=(M-2);j++)
		{
			if(s>0)
			{
				pro=(pro*robo[R2][j])%1000000007;
				s--;
			}
			else
				break;
		}


		M=M-1,z1=z1+1;
		N=N-1,z2=z2+1;
		X=X+1,z3=z3+1;
		W=W+1,z4=z4+1;
		}

		printf("%lld\n",pro%1000000007);
		t--;
	}
	return 0;
}



		






