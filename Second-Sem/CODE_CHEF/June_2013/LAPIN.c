#include<stdio.h>
#include<string.h>
int main()
{
     int i=0,t;
     int mid=0,j;
     char arr[1001];
 
     scanf("%d",&t);
     while(t--)
     {
	  int fre[26]={0};
	  scanf("%s",arr);
	  mid=strlen(arr)/2;
	  for(i=0,j=strlen(arr)-1;i<mid;i++,j--)
	  {
	       fre[arr[i]-'a']++;
	       fre[arr[j]-'a']--;
	  }
	  for(i=0;i<26;i++)
	  {
	       if(fre[i]!=0)
		    break;
	  }
	  if(i==26)
	       printf("YES\n");
	  else
	       printf("NO\n");
     }
     return 0;
}
