#include<stdio.h>
#define MAX 1000
int main()
{
 
long long int i, j,sum, sieve[MAX], primecount=0, prime[MAX];
 
for(i=0; i<MAX; i++)
{
	        sieve[i]=1;
}
sieve[0]=sieve[1]=0;
for(i=2; i<MAX; i++)
{
	   while(sieve[i]==0 && i<MAX)
	   {
		   i++;
	   }
		    prime[primecount]=i;
			     for(j=i*i; j<MAX; j+=i)
			     {
				     sieve[j]=0;
			     }
				        primecount++;
					sum=sum+i;
					printf("%lld\n",i);
}

printf("%lld\n",sum%8658);
printf("%lld\n",primecount);
return 0;
}

