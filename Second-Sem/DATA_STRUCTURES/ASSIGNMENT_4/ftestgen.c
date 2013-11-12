#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t=3000,i;
	while(t--)
	{
		int n=rand()%198+2;
		printf("%d\n",n);
		for(i=0;i<n;i++)
			printf("%d %d ",rand()%1000,rand()%1000);
		printf("\n");
	}
	printf("0\n");
}
