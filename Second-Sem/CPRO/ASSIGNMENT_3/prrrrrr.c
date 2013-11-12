#include<stdio.h>
int main()
{
	int t,n,sum,i,j,c=0,sum_perfect=0,is_perfect=0,flag;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		sum=0;
		is_perfect=0;
		sum_perfect=0;
		for(i=2;i<=n;i++)
		{
			is_perfect=0;
			flag=1;
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{
					flag=0;
					is_perfect+=j;
				
				}
			}
			if((is_perfect+1)==i)
			{
				printf("%d\n",is_perfect+1);
				/*sum_perfect+=i;*/
			}

			if(flag==1)
				
			{
				sum+=i;
			}

		}
	/*	c=(sum)%(sum_perfect);*/
		/*printf("%d\n",c);*/
		t--;
	}
	return 0;
}





