/* ANAGRAMS IN A STRING */


#include<stdio.h>
#include<string.h>
char arr[1000001];
char brr[100001];
int main()
{
     int t,k,ans;
     int n,l;
     int i,cnt;
     scanf("%d",&t);
     while(t--)
     {
	  ans=0;
	  cnt=0;
	  k=0;
	  
	  int check[28]={0};
	  int fre[28]={0};
	  
	  scanf("%s",arr);
	  scanf("%s",brr);
	  n=strlen(arr);
	  l=strlen(brr);
	 
	  
	  for(i=0;i<l;i++)
	       check[brr[i]-'a']++;

	  for(i=0;i<n;i++)
	  {
	       fre[arr[i]-'a']++;
	       cnt++;
	       while(fre[arr[i]-'a']>check[arr[i]-'a'])
	       {
		    cnt--;
		    fre[arr[k]-'a']--;
		    k++;
	       }
	       if(cnt==l)
	       {
		    ans++;
	       }
	  }
	  printf("%d\n",ans);
     }
     return 0;
}
