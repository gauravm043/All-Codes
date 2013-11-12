#include<stdio.h>
int addv(int s,int t);
int addr(int*s,int*t);
int main()
{
	int a,b,c,cv,cr,d;
	scanf("%d%d",&a,&b);
	cv=addv(a,b);
	printf("cv %d %d %d\n",cv,a,b);
	cr=addr(&a,&b);
	printf("cr %d %d %d\n",cr,a,b);
	return 0;
}
int addv(int x,int v)
{
	int m;
	m=x+v;
	x=x+100;
	v=v+10;
	return m;
}

int addr(int*x,int*v)
{
	int m;
	m=*x+*v;
	*x=*x+100;
	*v=*v+10;
	return m;
}





	
