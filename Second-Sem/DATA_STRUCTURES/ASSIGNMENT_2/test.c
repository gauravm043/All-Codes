#include<stdio.h>
#include<string.h>
int main()
{
     char a[100],b[100];
     scanf("%s",a);
     scanf("%s",b);
     strcat(a,b);
     printf("%s",a);
     return 0;
}
