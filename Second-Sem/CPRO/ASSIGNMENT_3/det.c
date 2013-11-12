#include<stdio.h>
int main()
{
	int  t,n,i,k,j,row,zero=0,m;
	float x,pro,a[10][10];
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%f",&a[i][j]);
			}
		}

		k=0,row=1;	
		for(j=0;j<n;j++)
			{
				for(i=n-1;i>=row;i--)
				{
					
				
						x=a[i][j]/a[k][k];
					
						
						for(m=zero;m<n;m++)
						{
					        a[i][m]=a[i][m]-x*a[j][m];
						/*printf("\t%0.3f",a[i][m]);*/
					        }
					
					
				}
				
				
				zero++;	
				row++;
					k++;
				
			}

		pro=a[0][0]*a[1][1]*a[2][2]*a[3][3]*a[4][4]*a[5][5];
		printf("%0.0f",pro);
		pro=1;
		
		printf("\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				printf("%0.3f",a[i][j]);
			printf("\n");
			
		}
			printf("\n");
			printf("%0.0f",pro);
		

		t--;
	}
	return 0;
}


		
			
			
		

	
				     





