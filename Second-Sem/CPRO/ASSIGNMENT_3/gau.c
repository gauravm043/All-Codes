#include<stdio.h>
#define MAX 1000
int main()
{
 
long long int i, j,sum, PRIME[MAX]={1}, track=0, count[MAX];

PRIME[0]=PRIME[1]=0;
for(i=2; i<MAX; i++)
{
	   while(PRIME[i]==0 && i<MAX)
	   {
		   i++;
	   }
		    count[track]=i;
			     for(j=i*i; j<MAX; j+=i)
			     {
				     PRIME[j]=0;
			     }
				        track++;
					sum=sum+i;
					printf("%lld\n",i);
}

printf("%lld\n",sum%8658);
printf("%lld\n",track);
return 0;
}

