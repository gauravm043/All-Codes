#include<stdio.h>
int main()
{
	int t,n,i,j,r1,f=1,r2,r3,r4,c1,c2,c3,c4;
	scanf("%d",&t);
	while(t!=0)
	{
     
		scanf("%d",&n);
		int chess[n][n];
		f=1;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				scanf("%d",&chess[i][j]);
			}
		}


		/* CHECKING*/

		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				r1=i+2,c1=j-1;
				r2=i-2,c2=j+1;
				r3=i-1,c3=j-2;
				r4=i+1,c4=j+2;
				if(chess[i][j]==2)
				{

					if(r1<n)
					{

				
					if(c1>=0)
					{
						if(chess[r1][c1]==2)
						{
					   
							f=0;
			
						}
					}

					if(c2<n)
					{
						if(chess[r1][c2]==2)
						{
							f=0;
				
						}
					}
					
					}

				


					if(r2>=0)
				{
					if(c1>=0)
					{
						if(chess[r2][c1]==2)
						{

							f=0;
		
						}
					}

					if(c2<n)
					{
						if(chess[r2][c2]==2)
						{
						
							f=0;
						}
					}
				}

				if(c4<n)
				{
					if(r3>=0)
					{
						if(chess[r3][c4]==2)
						{
							f=0;
					
						}
					}
					if(r4<n)
					{
						if(chess[r4][c4]==2)
						{
				
							f=0;
					
						}
					}
				}

				if(c3>=0)
				{
					if(r3>=0)
					{
						if(chess[r3][c3]==2)
						{
							
							f=0;
		
						}
					}
					if(r4<n)
					{
						if(chess[r4][c3]==2)
						{
					
							f=0;
						
						}
					}
				}
			
				}
			}
		}

			if(f==1)
			printf("SAFE\n");
			else
			printf("RISKY\n");
			
			



		t--;
	}

	
		return 0;
}








				








