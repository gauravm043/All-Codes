#include<stdio.h>
char arr[1000000];
char brr[100000];
char check[26]={0};
char fre[26]={0};
int main()
{
     int t,i,cnt;
     scanf("%d",&t);
     while(t--)
     {
	  cnt=0;
	  scanf("%s",arr);
	  scanf("%s",brr);
	  n=strlen(arr);
	  cnt=strlen(brr);
	  l=cnt;

	  /* FREQUENCY ARRAY */
	  for(i=0;i<n;i++)
	  {
	       check[arr[i]-'a']++;
	       fre[arr[i]-'a']++;
	  }

	  /*  CALCULATING */

	  for(i=0;i<n;i++)
	  {
	       if(fre[arr[i]-'a']!=0)
	       {
		    fre[arr[i]-'a']--;
		    cnt--;
	       }

	       if(cnt==0)
	       {
		    ans++;
		    if(fre[arr[i-l+1]]>=0)
		    {
			 cnt++;
		    }

		    fre[arr[i-l+1]]--;
		    while(1)
		    {
			 i++;
			 if(check[arr[i]]!=0)
			 {
			      fre[arr[i]]++;

	       }
	  }




