#include<stdio.h>
int main()
{
	int*ptr;
	int a=5;
	ptr=&a;
	printf("%p\n",ptr);
	printf("%d\n",*ptr);
	//printf("%p\n",*(*ptr));
	return 0;
}

