#include<stdio.h>

int tohsteps(int n)
{
if(n==1)
return 1;
else
return (2*tohsteps(n-1)+1);
}

int main()
{
int n,x;
scanf("%d",&n);
x=tohsteps(n);
printf("%d",x);
return 0;
}
