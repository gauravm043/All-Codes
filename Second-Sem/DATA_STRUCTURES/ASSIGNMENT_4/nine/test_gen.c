#include<stdio.h>
#include<stdlib.h>
int main()
{
     int n=100;
     printf("10\n");
     while(n--)
     {
	  printf("%d %d %d\n",rand()%4+1,rand()%10,rand()%10);
     }
     return 0;
}
