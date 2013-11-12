#include<stdio.h>
int M[1000000]={0};
int M2[1000000]={0};
int main()
{
     int t,f;
     int i,j,k;
     int n,num;
     scanf("%d",&t);
     while(t!=0)
     {
	  for(i=0;i<1000000;i++)
	  {
	       M2[i]=0;
	       M[i]=0;
	  }
	  f=0;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	  {
	       scanf("%d",&num);
	       if (num<0)
	       {
		    num=num*(-1);
		    M2[num]++;
	       }
	       else
	       M[num]++;
	  }

	  for(i=0;i<1000000;i++)
	  {
	       if(M[i]>n/2)
	       {
		    printf("%d\n",i);
		    t--;
		    f=1;
		    break;
	       }
	       
	  }
	  if(f==1)
	       continue;

	  for(i=0;i<1000000;i++)
	  {
	       if(M2[i]>n/2)
	       {
		    printf("%d\n",i*-1);
		    t--;
		    break;
	       }
	  }
     }
     return 0;
}
