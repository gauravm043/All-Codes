#include<stdio.h>
int a=5;
int rec(int a)
{
     if(a==0)
	  return 1;
     else
	  a=a-1;
     return rec(a);
}
int main()
{
     int b;
     printf("a before:%d\n",a);
     b=rec(a);
     printf("a after:%d b after:%d\n",a,b);
     return 0;
}
