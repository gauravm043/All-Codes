#include<stdio.h>
#include<string.h>
char arr[100000];

void copy(int check[],int tmp[])
{
     int i;
     for(i=0;i<125;i++)
	  check[i]=tmp[i];
}

void print(int check[])
{
     int i;
     for(i=0;i<125;i++)
     {
	  if(check[i]!=0)
	       printf("%c-->%d\n",i,check[i]);
     }
}
int main()
{
     int t,i,x,y,c;
     int l,n,pos,count;
     char ch,flag=1;
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
	  c=getchar();


	  while(ch!='\n')
	  {
	       l++;
	       scanf("%c",&ch);
	       check[ch]++;
	       tmp[ch]++;
	  }
	  l--;
	  printf("l-->%d",l);
	  print(check);

	  for(i=0;i<n;i++)
	  {
	       y++;
	       if(check[arr[i]]==0)
	       {
		    x=0;
		    y=0;
		    copy(check,tmp);
	
		    continue;
	       }
	       if(check[arr[i]]!=0)
	       {
		    check[arr[i]]--;
		    x++;
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
