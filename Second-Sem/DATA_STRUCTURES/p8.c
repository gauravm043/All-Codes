#include<stdio.h>
int main()
{
     int t,ans;
     int a,b,c,m,n;
     scanf("%d",&t);
     while(t--)
     {
	  scanf("%d%d%d",&m,&n,&c);
	  a=m>n?m:n;
	  b=m<n?m:n;
	  if(a==c||b==c)
	  {
	       printf("1\n");
	       continue;
	  }
	  if(c>b&&c<a)
	  {
	       if(c%b!=0)
	       {
		    if((a-c)%b==0)
		    {
			 printf("%d\n",((a-c)/b)*2);
			 continue;
		    }
		    
		    if(b-(a%b)!=c%b)
		    {
			 printf("-1\n");
			 continue;
		    }
		    else
		    {
			 c=c-c%b;
			 ans=((a/b)+1)*2+2+(c/b)*2;
		    }
		    printf("%d\n",ans);

	       }
	   
	  }

	  ans=CALCULATE(a,b,c);
	  printf("%d\n",ans);
     }
     return 0;
}

int CALCULATE(int a,int b,int c)
{
     int m,n;

     /* IF C IS GREATER */

     if(c>a&&c>b)
	  return -1;

     /* IF C IS SMALLER THAN A AND B */

     if(c<a&&c<b)
     {

	  if((b-a%b)==c)
	      return (a/b)*2;
	  else
	       return -1;
     }

     /* IF C IS IN BETWEEN A AND B */

     /* IF C DIVIDES BOTH A AND B */
     if(a%b==0&&c%b==0)
     {
	  m=((a-c)/b)*2;
	  n=(c/b)*2;
	  m=m<n?m:n;
	  return m;
     }

     if(a%b==0&&c%b!=0)
     {
	  return -1;
     }

     if(a%b!=0&&c%b==0)
	  return (c/b)*2;

}
