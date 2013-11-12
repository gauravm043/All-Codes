#include<stdio.h>
int p=0;
void hanoi(int n,char src,char dest,char temp)
{
p++;
if(n==0)
return;
hanoi(n-1,src,temp,dest);
printf("Move %d from %c to %c\n",n,src,dest);
hanoi(n-1,temp,dest,src);
}

int main()
{
int n;
scanf("%d",&n);
hanoi(n,'A','C','B');
printf("%d",p);
}

