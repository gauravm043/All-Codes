#include<stdio.h>
int main()
{	int t;
	scanf("%d",&t);
	while(t--)
	{	int i,n,a;
		scanf("%d",&n);
		scanf("%d",&n);
		int freq1[100]={0},ctr;
		for(i=0;i<n;i++)
		{	scanf("%d",&a);
 			freq1[a]=-1;
		}
		scanf("%d",&n);
		ctr=n;
		for(i=0;i<n;i++)
		{	scanf("%d",&a);
			if(freq1[a]==-1)
				ctr--;
		}
		printf("%d\n",ctr);
	}
	return 0;
}
