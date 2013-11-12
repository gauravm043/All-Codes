#include<stdio.h>
void bin(int num);
int main()
{
	int x;
	scanf("%d",&x);
	bin(x);
	return 0;
}

void bin(int n)
{
	if(n==0)
	return;
        bin(n/2);
	printf("%d",n%2);
	return;
}

