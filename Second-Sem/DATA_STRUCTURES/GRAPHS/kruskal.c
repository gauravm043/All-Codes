#include<stdio.h>
#include<stdlib.h>
int size[100],parent[100],n,m;
typedef struct node{
     int u;
     int v;
     int weight;
}node;
node g[100];
int findset(int i)
{
     if(parent[i]==-1)
	  return i;
     int retVal = findset(parent[i]);
     parent[i] = retVal;
     return retVal;
}
void Union(int p1,int p2)
{
     if(size[p2]>size[p1])
     {
	  int temp=p1;
	  p1=p2;
	  p2=temp;
     }
     parent[p2]=p1;
     size[p1]+=size[p2];
}
int main()
{
     int i,j,k,q,a[100],u,v,p1,p2,z,w;
     scanf("%d%d",&n,&m);
     for(i=0;i<m;i++)
     {
	  scanf("%d%d%d",&g[i].u,&g[i].v,&g[i].weight);
	  parent[i]=-1;
	  size[i]=1;
     }
     int small;
     for(i=0;i<m;i++)
     {
	  small=g[i].weight;
	  for(j=i+1;j<m;j++)
	  {
	       if(g[j].weight<small)
	       {
		    small=g[j].weight;
		    node temp;
		    temp=g[j];
		    g[j]=g[i];
		    g[i]=temp;
	       }
	  }
     }
     for(i=0;i<m;i++)
     {
	  if(findset(g[i].u)!=findset(g[i].v))
	  {
	       printf("%d %d %d\n",g[i].u,g[i].v,g[i].weight);
	       Union(findset(g[i].u),findset(g[i].v));
	  }
     } 
     return 0;
}
