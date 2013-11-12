#include<stdio.h>
int main()
{
	int n,k,i,j,t;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d %d",&n,&k);
		int array[n+k];
		for(i=k;i<(n+k);i++)
		{
		      scanf("%d",&array[i]);
		      array[i-k]=array[i];
		}
		for(i=k;i<n;i++)
		{
			printf("%d ",array[i]);
		}
		for(i=0;i<k;i++)
		{
			printf("%d ",array[i]);
		}
		t--;
	}
	return 0;
}

