#include<stdio.h>
#include<string.h>
char arr[1000000];
int main()
{
     long long int t;
     int i,x,y,c;
     long long int cnt,sum,count;
     int l,n,pos;
     char ch;
     int j;
     scanf("%lld",&t);
     ch=getchar();
     while(t--)
     {
	  int check[256]={0};
	  int tmp[256]={0};
	  ch='a';
	  l=0,count=0,x=0,y=0;
	  scanf("%s",arr);
	  n=strlen(arr);
	  c=getchar();
	  sum=0;

	  while(ch!='\n')
	  {
	       l++;
	       scanf("%c",&ch);
	       if(ch!='\n')
	       {
		    check[ch]++;
		    tmp[ch]++;
		    sum++;
	       }
	  }
	  l--;
	  cnt=sum;

	  for(i=0;i<n;i++)
	  {

	       y++;
	       if(check[arr[i]]!=0)
	       {
		    check[arr[i]]--;
		    cnt--;
		    x++;
	       }
	       else
	       {
		    x=0;
		    y=0;
		    if(cnt<sum)
		    {
			 sum=0;
			 for(j=0;j<256;j++)
			 {
			      check[j]=tmp[j];
			      sum+=tmp[j];
			 }
			 cnt=sum;
		    }
		    i--;
			 continue;
	       }

	       if(y==l&&x==l)
	       {
		    count++;
		    check[arr[i-l+1]]++;
		    x--;
		    y--;
		    if(tmp[arr[i+1]]!=0)
		    {
			 i=i-l+2;
		    }

	       }

	  }

	  printf("%lld\n",count);
     }
     return 0;
}
