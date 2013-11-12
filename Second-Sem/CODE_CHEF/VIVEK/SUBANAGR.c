#include<stdio.h>
#include<ctype.h>
#include<malloc.h>
#include<string.h>
#define min fre[i]<temp[i]?fre[i]:temp[i]

int main()
{
     int i,n;
     int test,attempt=1;;
     char str[101];
     int fre[26]={0};
     scanf("%d",&n);
     while(n--)
     {
	  int temp[26]={0};
	  scanf("%s",str);
	  for(i=0;i<strlen(str);i++)
	  {
	       temp[str[i]-'a']++;
	       if(attempt==1)
		    fre[str[i]-'a']++;
	  }

	  attempt=0;

	  for(i=0;i<26;i++)
	  {
		    fre[i]=min;
	  }

     }

     for(i=0;i<26;i++)
     {
	  while(fre[i]>0)
	  {
	       attempt=1;
	       printf("%c",i+'a');
	       fre[i]--;
	  }
     }
     if(!attempt)
	  printf("no such string"); 
     printf("\n");
     return 0;
}
