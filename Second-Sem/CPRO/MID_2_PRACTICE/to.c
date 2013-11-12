#include<stdio.h>
void han(int w,char src,char temp,char dest);

int main()
{
	int n;
	scanf("%d",&n);
	han(n,'A','B','C');
	return 0;
}


void han(int n,char src,char temp,char dest)
{

	if(n==0)
		return;
	han(n-1,src,dest,temp);
	printf("MOVE FROM %c TO %c \n",src,dest);
	han(n-1,temp,src,dest);
//	printf("MOVE FROM %c TO %c \n",src,dest);
	return;
}

