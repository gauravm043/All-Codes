#include<stdio.h>
int main()
	{
		int t,n;
		scanf("%d",&t);
		while(t!=0)
		{
			int a,i,g,c,b;
			a=0,b=1;
			scanf("%d",&n);
			if(n==1)
				printf("%d",a);
			if(n==2)
				printf("%d",b);
			n=n-2;
			while(n!=0)
			{
				g=a+b;
				c=g%100000;
				a=b;
				b=c;
				n--;
			}
			printf("%d\n",c);
		t--;
		}
		return 0;
	}



