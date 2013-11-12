#include<stdio.h>
#include<stdlib.h>
int main()
{
	int aa=42;
	printf("42\n");
	while(aa--)
	{
	int t=rand()%10;
	if(t!=0)
	{
	printf("%d\n",t);
	while(t--)
	{
		int y=rand()%10;
		int i;
		printf("%d ",y);
		for(i=0;i<y;i++)
			printf("%d ",rand()%20);
		printf("\n");
	}
	}
	else
	     aa++;

	}
}
