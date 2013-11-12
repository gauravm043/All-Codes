#include<stdio.h>
int main()
{
int x,r,y,a,b;
int t,d,c;
a>=0;
b>=0;
scanf("%d",&t);
while(t!=0)
{
scanf("%d%d",&a,&b);
x=a;
y=b;
while(y!=0)
{
r=x%y;
x=y;
y=r;
}
c=a*b;
d=c/x;
printf("%d\n",d);
t--;
}
return 0;
}

               
