#include<stdio.h>


int ANS(int a,int b,int c)
{
     int s=0;
     int v1=a;
     int v2=b;
     int tmp;

     while(a!=c&&b!=c)
     {
	  
	  if(b==0)
	  {
	       s++;
	       b=v2;
	  }
	  else if(a==v1)
	  {
	       s++;
	       a=0;
	  }
	  else
	  {
	       if(a+b>v1)
	       {
		    b=a+b-v1;
		    a=v1;
	       }
	       else
	       {
		    a=a+b;
		    b=0;
	       }
	       s++;
	  }
	  
	  if(v1-a==c)
	       break;
	  
     }
     return s;
}


int main()
{
     int t,x,r,st1,st2;
     int a,b,c,tmp,ans;
     scanf("%d",&t);
     while(t--)
     {
	  scanf("%d%d%d",&a,&b,&c);
	  int r,s,t;
	  int p=a>b?a:b;
	  int q=a>b?b:a;
	  s=p;
	  t=q;
	  while(q!=0)
	  {
	       r=p%q;
	       p=q;
	       q=r;
	  }
	  

	  /* CONSIDERING SPECIAL CASES */

	  if(c==0)
	  {
	       printf("0\n");
	  }
	  else if(a==c||b==c)
	  {
	       printf("1\n");
	  }
	  else if(c>a&&c>b)
	  {
	       printf("-1\n");
	  }
	  else if(c%p!=0)
	  {
	       printf("-1\n");
	  }
	  else if(c%p==0)                                                   /* MANUALLY U NEED TO CALCULATE */
	  {
	       st1=ANS(s,t,c);
	       printf("%d\n",st1);
	  }
	  else
	       printf("-1\n");
     }
     return 0;
}
