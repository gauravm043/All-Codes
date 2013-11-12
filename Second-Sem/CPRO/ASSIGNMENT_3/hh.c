#include<stdio.h>
int main()
{
	double  t,n=6,flag=0,row,zero=0;
	double x,pro;
	double a[6][6];
	int i,v,j,m,shi,k,te,term;
	scanf("%lf",&t);
	while(t!=0)
	{
                term=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%lf",&a[i][j]);
			}
		}

		k=0,row=1,zero=0;	
		for(j=0;j<n;j++)
			{      for(i=n-1;i>=row;i--)
				{
					if(a[i][j]!=0)
					{
					           if(a[k][k]==0)
						   {
						   te=k;
						   for(v=te+1;v<6;v++)
						   {
						   if(a[te][v]!=0)
						   {
						   term=v;
						   }
						   }
						   if(term!=0)
						   {
						   for(shi=0;shi<6;shi++)
						   {
						   a[shi][k]=a[shi][k]+a[shi][term];
						   }
						   }
						   }
						   
						   if(a[k][k]!=0)
						   {
							   x=a[i][j]/a[k][k];
					
						
						for(m=zero;m<n;m++)
						{
					        a[i][m]=a[i][m]-x*a[j][m];
					        }
						   }
						   
					}
					}
				zero++;	
				row++;
			        k++;
				
			}

		pro=a[0][0]*a[1][1]*a[2][2]*a[3][3]*a[4][4]*a[5][5];
		if(pro!=-0)
		
			printf("%0.0lf\n",pro);
		else
			printf("0\n");
                lb:
                t--;
	}
	return 0;
}


		
			
			
		

	
				     





