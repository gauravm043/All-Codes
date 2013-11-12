#include<stdio.h>
int main()
{
	long long int n,sum,term=1,test,num,t;
	int l,i,k,j;
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%d",&l);
		for(i=0;i<l;i++)
		{
			
			for(j=0;j<=i;j++)
			{
				if(i==0)
				{
					printf("1");
				}
				else if(j==0)
				{
					printf("1");
				}
				else
				{

				    term=i/j;
					for(test=1;test<=j;test++)
				{
			
				
							term=term*(i-1)/(j-1);
				}
				printf("%lld",term);
				}


			}
		printf("\n");
		}
		t--;
	}
	return 0;
}






		

