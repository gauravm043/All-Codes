#include<stdio.h>
int main()
{
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d %d %d",&n,&m,&s);
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&robo[i][j]);

                ia=ib=m-1;
		ja=0,jb=n-1,k=1;
		a1=m-1,b1=m-1,c1=0,c2=n-1;
		a2=n-1,b2=n-1,c2=m-1,d2=0;
		a3=0,b3=0,c3=n-1,d3=0;


		
                lb:
		while(s!=0)
		{
			if(k==1)
			{
				for(i=a1;i<=b1;i++)
				for(j=c1;j<=d1;j++)
					pro*=robo[j][i];
			}
			k=2;
			}


			if(k==2)
			{
				for(i=a2;i<=b2;i++)
				for(j=c2;j2>=d2;j--)
					pro*=robo[i][j];
				
				k=3;
			}

			if(k==3)
			{
				for(i=a3;i<=b3;i++)
					for(j=c3;j>=d3;j--)
						pro*=robo[j][i];

				k=4;
			}

			if(k==4)
			{
				for(i=







				



