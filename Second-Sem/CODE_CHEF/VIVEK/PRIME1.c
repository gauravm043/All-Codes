#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define size 100000

int temp[39]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,137,139,149,151,157,163,167,173};
int arr[31624]={0};
int PRIME[3416];

int main()
{
     double div;
     int i,SIZE=0,test;
     int p,j;
     int m,n,diff,k;
     int ANS[100000];
     
     for(i=0;i<39;i++)
     {
	  p=temp[i];
	  for(j=2*p;j<31624;j+=p)
	  {
	       arr[j]=-1;
	  }
     }

     /* PRIME ARRAY */
     arr[0]=arr[1]=-1;

     for(i=0;i<31624;i++)
     {
	  if(arr[i]==0)
	       PRIME[SIZE++]=i;
     }
   


     /* TAKING INPUT */
     int lower;

     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d%d",&m,&n);
	  lower=m;
	  for(i=0;i<100000;i++)
	       ANS[i]=0;
	  if(m==1)
	  ANS[0]=-1;


	  diff=n-m+1;
	  for(i=0;i<SIZE;i++)
	  {
	       if(PRIME[i]<n)
	       {
		    div=(double)(m)/PRIME[i];
		    k=ceil(div);
		    if(k==1)
			 p=PRIME[i]*2-m;
		    else
			 p=PRIME[i]*k-m;
		    while(p<diff)
		    {
			 ANS[p]=1;
			 p+=PRIME[i];
		    }
	       }
	  }
	  for(i=0;i<diff;i++)
	  {
	       if(ANS[i]==0)
		    printf("%d\n",i+lower);
	  }
	  printf("\n");
     }
     return 0;
}
