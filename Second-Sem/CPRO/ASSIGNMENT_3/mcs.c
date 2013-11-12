#include<stdio.h>
int main()
{
	int t,max,j,n,i,sum,k=0;
    int arr[300000],summ[300000];
	while(1)
	{

		
		scanf("%d",&n);
		if(n==0)
            return 0;



		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

                k=0;
		for(i=0;i<n;i++)
		{
			sum=0;
		        for(j=i;j<n;j++)
			{
				sum=sum+arr[j];
				summ[k]=sum;
				k++;
			}
		}
		k--;

		max=summ[0];
		for(i=0;i<=k;i++)
		{
			if(summ[i]>max)
				max=summ[i];
		}

	
			printf("%d\n",max);

	 	
	}
	return 0;
}




