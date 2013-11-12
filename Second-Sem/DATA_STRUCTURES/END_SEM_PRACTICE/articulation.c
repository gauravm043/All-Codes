#include<stdio.h>
#include<stdlib.h>
typedef struct grap
{
     int v;
     struct grap*next;
}
node;

node*graph[100]={NULL};
int visited[100]={0};
int parent[100]={0};
int time[100]={0};
int times=0;
int low[100]={0};


void dfs(int v)
{
     time[v]=++times;
     visited[v]=1;
     node*tmp;
     tmp=graph[v];
     while(tmp!=NULL)
     {
	  if(visited[tmp->v]==0)
	  {
	       parent[tmp->v]=v;
	       dfs(tmp->v);
	  }
	  tmp=tmp->next;
     }
     return;
}

void assign_low(int v)
{
     int w;
     low[v]=time[v];
     node*tmp;
     tmp=graph[v];
     while(tmp!=NULL)
     {
	  w=tmp->v;
	  if(time[w]>time[v])
	  {
	       assign_low(w);
	       if(low[w]>=time[v])
		    printf("%d   is an articulation point\n",v);
	       low[v]=low[v]<low[w]?low[v]:low[w];
	  }
	  else
	       if(parent[v]!=w)
		    low[v]=low[v]<time[w]?low[v]:time[w];
          tmp=tmp->next;
     }
}


	 
int main()
{
     node*new;
     int u,v,i;
     int m,n;
     scanf("%d %d",&n,&m);
     for(i=0;i<=n;i++)
	  parent[i]=-1;
     while(m--)
     {
	  scanf("%d%d",&u,&v);
	  new=(node*)malloc(sizeof(node));
	  new->v=v;

	  new->next=graph[u];
	  graph[u]=new;

     }


     //	DFS

     dfs(1);

//     for(i=1;i<=n;i++)
//	  printf("%d     %d     %d\n",i,parent[i],time[i]);

     assign_low(1);

     return 0;
}
