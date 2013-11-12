#include<stdio.h>
int M[101]={0};
int main()
{
     int i,t,na,nb,flag=0;
     long int sum=0;
     int limit,num;
     scanf("%d",&t);
     while(t!=0)
     {
	  flag=0;
	  for(i=0;i<101;i++)
	       M[i]=0;
	  sum=0;
	  t--;
	  scanf("%d",&limit);
	  scanf("%d",&na);
	  for(i=0;i<na;i++)
	  {
	       scanf("%d",&num);
	       M[num]=-1;
	  }
	  scanf("%d",&nb);
	  for(i=0;i<nb;i++)
	  {
	       scanf("%d",&num);
	       if(M[num]!=-1)
	       M[num]=M[num]+1;
	  }

	  for(i=0;i<limit;i++)
	  {
	       flag=1;
	       if(M[i]!=-1)
	       sum+=M[i];
	  }

	  printf("%ld\n",sum);

     }
     return 0;
}
