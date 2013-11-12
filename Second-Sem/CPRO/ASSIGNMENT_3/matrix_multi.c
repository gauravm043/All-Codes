#include<stdio.h>
int main()
{
	long long int t,p,q,status=1,g1,g2,i,j,m,n,k,harami,check=0,final[200][200],C[200][200];                             
	scanf("%lld",&t);
	while(t!=0)
	{
		       status=1;       
		       scanf("%lld",&harami);
                       scanf("%lld %lld",&p,&q);
			long long int A[p][q];
			g1=p;
			for(i=0;i<p;i++)
			{
				for(j=0;j<q;j++)
				{
					scanf("%lld",&A[i][j]);
				}
			}
		        check=2; 
                        while(check!=harami+1)
			
			{
				scanf("%lld %lld",&m,&n);
				long long int B[m][n];
			       for(i=0;i<m;i++)
				{
			                for(j=0;j<n;j++)
					{
						scanf("%lld",&B[i][j]);
					}
				}
                                if(check==2)
				{
				if(m==q)
				{
					for(i=0;i<p;i++)
				
					{
				
						for(j=0;j<n;j++)
						{
						     C[i][j]=0;
							for(k=0;k<m;k++)
						     {
							     C[i][j]=(C[i][j]%1000000007+(A[i][k]*B[k][j])%1000000007)%1000000007;
						     }
					
						
						}
					}
				}
				else
				{
					status=0;
				
				}
				}
			
		               if(check!=2)
				{
				
				
					if(m==g2)
				{
				
					for(i=0;i<g1;i++)
					{
						for(j=0;j<n;j++)
						{
							final[i][j]=0;
							for(k=0;k<g2;k++)
							{
								final[i][j]=final[i][j]%1000000007+(C[i][k]*B[k][j]%1000000007)%1000000007;
							}
					
		
						}
					}
				}
				
					else
					{
						status=0;
						
					}
				}

				
				

			       /*else
				       printf("1111111");*/
			       if(check>2)
			       {
				for(i=0;i<g1;i++)
				{
					for(j=0;j<n;j++)
					{
						C[i][j]=final[i][j];
					}
				}
			       }


				
				g2=n;
			check++;    
			}
			
			


			if(status==1)
			{   
				printf("%lld %lld",g1,g2);
				printf("\n");
			    for(i=0;i<g1;i++)
			    {
				    for(j=0;j<g2-1;j++)
				    {
					    printf("%lld ",C[i][j]);
				    }
				    printf("%lld",C[i][g2-1]);
				    printf("\n");
			    }
			}
			else
				printf("-1\n");
			    t--;
	}
	return 0;
}


		



			

		








							






