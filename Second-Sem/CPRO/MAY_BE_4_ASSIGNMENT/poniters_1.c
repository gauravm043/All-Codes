#include<stdio.h>
int main()
{
	char*x;
	float*y;

	char a=5,i=50;
	x=&a;
	printf("%p\n",x);
	
	
	while(i!=0)
		
	{
		printf("%p\n",x++);
		i--;
	}

	return 0;
}
