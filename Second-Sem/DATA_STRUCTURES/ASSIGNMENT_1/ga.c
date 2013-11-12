#include<stdio.h>
int main()
{	int t;
     int i,n,m,a;
     scanf("%d",&t);
     while(t--)
     {
	  scanf("%d",&m);
	  scanf("%d",&n);
	  int freq1[101]={0},ctr;
	  for(i=0;i<n;i++)
	  {
	       scanf("%d",&a);
	       if(a<100)
		    freq1[a]=-1;
	  }
	  scanf("%d",&n);
	  ctr=n;
	  for(i=0;i<n;i++)
	  {	scanf("%d",&a);
	       if(freq1[a]==-1&&a<100)
		    ctr--;
	  }
	  printf("%d\n",ctr);
     }
     return 0;
}
