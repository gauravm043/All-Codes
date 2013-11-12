#include<stdio.h>
int main()
{
	int t,tr,p,n,i,j,counter,c=1;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		int x[n];
		int w[n];
		for(i=0;i<n;i++)
			scanf("%d",&x[i]);
		for(i=0;i<n;i++)
			scanf("%d",&w[i]);
		counter=0,tr=0;
		p=x[0];
		for(i=0;i<=n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				
				if(x[i]==x[j])
				{
					if(w[i]==w[j])
					{
						if(x[i]!=p)
						{tr++;
						p=x[i];}
						x[j]=1100+c;
						counter++;
					}
					c++;
				}
			}
		}
		printf("%d\n",(n-counter));
		t--;
	}
	return 0;
}

		


