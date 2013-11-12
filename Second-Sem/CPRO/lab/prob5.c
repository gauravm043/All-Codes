#include<stdio.h>
int main()
{
	int t,x,y,w,q,r;
		scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d%d",&x,&y);
		r=x;
		q=0;
		w=y;
		while(w<=r)
		{
			w=2*w;
			while(w!=y)
			{
				q=2*q;
				w=w/2;
				if(w<=r)
				{
					r=r-w;
					printf("%d\n",q);
					q++;
				}
				printf("%d %d",q,r);

			}
		}
		t--;
	}
	return 0;
}


