#include<stdio.h>
typedef struct ele
{
     int w;
     int u;
     int v;
}
node;

int cmp(void const*a,void const*b)
{
     node*p=(node*)a;
     node*q=(node*)b;
     return(p->w-q->w);
}

int set[1000];
node edge[1000];

void union_it(int a,int b,int c);
int main()
{
     int n,m;
     int i;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
	  scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
	  set[i]=i;
     }

     /* SORTING */

     qsort(edge,m+1,sizeof(node),cmp);
  
     for(i=1;i<=m;i++)
     {
	  printf("%d-->>%d-->>>%d\n\n",edge[i].u,edge[i].v,edge[i].w);
     }
     /* KRUSKAL'S */
     for(i=1;i<=m;i++)
     {
	  if(set[edge[i].u]!=set[edge[i].v])
	  {
	       printf("%d  %d  %d\n",edge[i].u,edge[i].v,edge[i].w);
	       union_it(set[edge[i].u],set[edge[i].v],n);
	  }
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
