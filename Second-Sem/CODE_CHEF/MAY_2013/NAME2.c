#include<stdio.h>
#include<string.h>

char boy[25001];
char girl[25001];

int check(char*A,char*B)
{
     int i,j=0;
     for(i=0;i<strlen(A);i++)
     {
	  if(j==strlen(B))
	       return 1;
	  if(B[j]==A[i])
	  {
	       j++;
	  }
     }
     if(j==strlen(B))
	  return 1;
     return 0;
}

int main()
{
     int t;
     int ans;
     scanf("%d",&t);
     while(t--)
     {
	  scanf("%s",boy);
	  scanf("%s",girl);
	  ans=check(boy,girl);
	  if(!ans)
	       ans=check(girl,boy);
	  if(!ans)
	       printf("NO\n");
	  else
	       printf("YES\n");
     }
     return 0;
}
