#include<stdio.h>
#include<string.h>
char arr[1000000];
int main()
{
     int t,i,x,y,c;
     int cnt,sum;
     int l,n,pos,count;
     char ch,flag=1;
     int j;
     scanf("%d",&t);
     c=getchar();
     while(t--)
     {
	  flag=0;
	  int check[125]={0};
	  int tmp[125]={0};
	  ch='a';
	  l=0,count=0,x=0,y=0;
	  scanf("%s",arr);
	  n=strlen(arr);


	  while(ch!=' ')
	  {
	       l++;
	       scanf("%c",&ch);
	       if(ch!=' ')
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
			 for(j=0;j<125;j++)
			 {
			      check[j]=tmp[j];
			      sum+=tmp[j];
			 }
			 cnt=sum;
			 i--;
			 continue;
		    }
		    else
		    {
			 continue;
		    }
	       }

	       if(y==l&&x==l)
	       {
		    count++;
		    check[arr[i-l+1]]++;
		    x--;
		    y--;
	       }

	  }

	  printf("%d\n",count);
     }
     return 0;
}
