#include<stdio.h>
int main()
	{

		int a,b,t,p,r;
		scanf("%d",&t);
		while(t!=0)
		{
			scanf("%d%d",&a,&b);
			int q=0;
			int r=a;
				while(r>=b)
				{
					r=r-b;
					q++;
					printf("%d\n",r);
				}
			printf("%d %d\n",q,r);

			t--;
		}
		return 0;
	}



