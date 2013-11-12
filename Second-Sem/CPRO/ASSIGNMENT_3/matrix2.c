#include<stdio.h>
int main()
{
	long long int t,i,j,d,a,k;                             
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%lld",&k);
		d=1,a=1;
		long long int r[k+1],c[k+1];
			scanf("%lld %lld",&r[d],&c[d]);
			long long int A[r[d]][c[d]];
			
			for(i=0;i<r[d];i++)
			{
				for(j=0;j<c[d];j++)
				{
					scanf("%lld",&A[i][j]);
				
				}
			
			}

			k=k-1;


			
			

		

                             lb:
				scanf("%lld %lld",&r[d+1],&c[d+1]);
				long long int B[r[d+1]][c[d+1]];
				for(i=0;i<r[d+1];i++)
			{
				for(j=0;j<c[d+1];j++)
				{
					scanf("%lld",&B[i][j]);
				}
				
				
			}
		
			
				long long int C[r[1]][c[d+1]];
				if(d==1)
					temp[r[1]][c[d+1]];
				long long int F[r[1]][c[d+1]];

				for(i=0;i<r[1];i++)
					{
						for(j=0;j<c[d+1];j++)
						{
						     if(d==1)
						     {
							C[i][j]=0;
							for(k=0;k<r[d+1];k++)
						     {
					                   C[i][j]=C[i][j]+A[i][k]*B[k][j];
						     }
							temp[i][j]=C[i][j];
						     }

						     else
						     {
							     F[i][j]=0;
							     for(k=0;k<r[d+1];k++)
							     {
								     F[i][j]=F[i][j]+temp[i][j]*B[k][j];
							     }
							     temp[i][j]=F[i][j];
						     }



						
							
						}
					}
				a++;
				k--;
				d++;
				if(k!=0)
					goto lb;
			 else
			      {

	

				for(i=0;i<r[1];i++)
				{
			
				for(j=0;j<c[d];j++)
				{
					printf("\t%lld",temp[i][j]);
				}
				printf("\n");
				}
                             
			      }
			
				
	

	

				
	
	
			
			

			
			t--;
	}
	
	return 0;
}





		








							






