#include<stdio.h>
int main()
{
	int  t,i,k,j,row,zero=0,m;
	float x,pro,a[10][10];
	scanf("%d",&t);
	while(t!=0)
	{
                   for(i=0;i<6;i++)
		{
			for(j=0;j<6;j++)
			{
				scanf("%f",&a[i][j]);
			}
		}
                 k=0,row=1;	
		for(j=0;j<6;j++)
			{
				for(i=5;i>=row;i--)
				{
					if(i!=j)
					{
					x=a[i][j]/a[k][k];
					for(m=zero;m<6;m++)
					{
					       a[i][m]=a[i][m]-x*a[j][m];
					}
					}
				}
				zero++;	
				row++;
					k++;
			}

		pro=a[0][0]*a[1][1]*a[2][2]*a[3][3]*a[4][4]*a[5][5];
		printf("%0.0f\n",pro);
		pro=1;
		t--;
	}
	return 0;
}


		
			
			
		

	
				     





