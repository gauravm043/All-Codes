#include<stdio.h>
void bin(int num,int base);
int main()
{
	int x,ba;
	scanf("%d %d",&x,&ba);
	bin(x,ba);
	return 0;
}

void bin(int n,int b)
{
	if(n==0)
	return;
        bin(n/b,b);
	printf("%d ",n%b);
	return;
}

