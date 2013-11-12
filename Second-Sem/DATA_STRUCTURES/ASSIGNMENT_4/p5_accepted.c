#include<stdio.h>
#include<math.h>
typedef struct point
{
	int x;
	int y;
}
arr;


typedef struct ele
{
	int u;
	int v;
	double w;
}
node;

int cmp(void const*a,void const*b)
{
	double ch;
	node*p=(node*)a;
	node*q=(node*)b;
	ch=p->w-q->w;
	if(ch>0)
		return 1;
	if(ch<0)
		return -1;
	return 0;

}


arr stone[201];
node edge[1000000];
int set[201];

void union_it(int a,int b,int c);
int main()
{
	int TIMES=1;
	while(1)
	{
		int n,m,j;
		int i,k=0;
		scanf("%d",&n);
		if(n==0)
			return 0;

		for(i=1;i<=n;i++)
		{
			set[i]=i;
			scanf("%d%d",&stone[i].x,&stone[i].y);
		}

		/* SORTING */

		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(i>j)
				{
					edge[k].u=i;
					edge[k].v=j;
					edge[k].w=sqrt(pow(stone[i].x-stone[j].x,2)+pow(stone[i].y-stone[j].y,2));
					k++;
				}
			}
		}
		qsort(edge,k,sizeof(node),cmp);
		/*	  for(i=0;i<k;i++)
			  {
			  printf("%d-->>%d-->>>%lf\n",edge[i].u,edge[i].v,edge[i].w);
			  }
		 */

		/* KRUSKAL'S */
		i=0;
		double max=0;
		while(1)
		{
			//printf("%lf\n",max);

			// if(set[edge[i].u]!=set[edge[i].v])
			{
				//	    printf("%d  %d  %lf\n",edge[i].u,edge[i].v,edge[i].w);
				max=edge[i].w;
				union_it(set[edge[i].u],set[edge[i].v],n);
			}
			i++;
			if(set[1]==set[2])
				break;
		}

		printf("Scenario #%d\n",TIMES++);
		printf("Frog Distance = %0.3lf\n\n",max);

	}
	return 0;

}

void union_it(int a,int b,int n)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(set[i]==b)
			set[i]=a;
	}
}

