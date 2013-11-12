#include<stdio.h>
int main()
{
long long int  i,n,pro=1;
scanf("%lld",&n);
for(i=n;i!=0;i--)
{
pro=pro*2;
}
printf("%lld",pro-1);
return 0;
}

