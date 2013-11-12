#include<stdio.h>
int main()
{
     int a,b,c,i;
     int m,n,min,p;
     int qualit[7]={-1};

     scanf("%d%d",&m,&n);
     while(m--&&n)
     {
	  scanf("%d%d%d",&a,&b,&c);
	  if(a>=1&&a<=6)
	  {
	       if(qualit[a]<c)
	       {
		    n=n-b;
		    qualit[a]=c;
	       }

	  }
     }

     min=qualit[1];
     for(i=1;i<=6;i++)
     {
	  if(min>qualit[i])
	       min=qualit[i];
	  if(qualit[i]==-1)
	  {
	       printf("0\n");
	       return 0;
	  }
     }
     printf("%d\n",min);
     return 0;
}
