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
			flag=1;
			for(j=2;j<i;j++)
			{
				if(i%j==0)
				{
					flag=0;
					is_perfect+=j;
					printf("%d\n",is_perfect);
				}

			}
			if(flag==1)
				
			{
				sum+=i;
				/*printf("%d\n",i);*/
			}

			if((is_perfect+1)==i)
				sum_perfect+=i;
		}
		c=(sum)%(sum_perfect+1);
		printf("%d",c);
		t--;
	}
	return 0;
}




