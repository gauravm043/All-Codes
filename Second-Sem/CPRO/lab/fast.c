#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t!=0)
	{
		long long int u,v,z,x,y;
		scanf("%lld%lld",&x,&y);
		z=0;
		v=x;
		u=y;
		while(u!=0)
		{
			if(u%2!=0)
			{
				z=z+v;
				printf("adding %lld\n",v);
			}
			u=u/2;
			v=2*v;
		}
		printf("%lld\n\n",z);
		t=t-1;
	}
	return 0;
	}





