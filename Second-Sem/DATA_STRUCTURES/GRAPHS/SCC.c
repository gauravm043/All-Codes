#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
     int data;
     int ft;
     struct list*next;
}
node;

typedef struct m
{
     int time;
     int v;
}
node_time;

int kk=0;
int time=-1;
node*graph[1000]={NULL};
node*graph_tra[1000]={NULL};
void print(int r);
void DFS(int v);
void dfs(int c);
node_time finish[10000];
int visited[1000]={0};

int cmp(void const*a,void const*b)
{
     node_time *p=(node_time*)a;
     node_time *q=(node_time*)b;
     if(p->time-q->time>0)
	  return -1;
     if(p->time==q->time)
	  return 0;
     return 1;
}

int main()
{
     int n,i,m;
     int num,wo;
     int h,j;
     scanf("%d%d",&m,&n);
     for(i=1;i<=n;i++)
     {
	  scanf("%d",&h);
	  scanf("%d",&wo);
	  node*new;
	  node*new2;
	  new=(node*)malloc(sizeof(node));
	  new->data=wo;
	  new->next=graph[h];
	  graph[h]=new;
	  new2=(node*)malloc(sizeof(node));
	  new2->data=h;
	  new2->next=graph_tra[wo];
	  graph_tra[wo]=new2;
     }
     node*tmp;
     for(i=1;i<=m;i++)
     {
	  if(visited[i]!=1)
	  {
	       DFS(i);
	  }
     }
     qsort(finish,kk,sizeof(node_time),cmp);
     int cnt=0;
    for(i=0;i<=m;i++)
     {
	  visited[i]=0;
     }

     /* Connected components */

     for(i=0;i<kk;i++)
     {

	  if(visited[finish[i].v]!=1)
	  {
	       dfs(finish[i].v);
	       ++cnt;
	  }
     }
     printf("SCC--->>%d\n",cnt);


     return 0;
}
void dfs(int v)
{
     visited[v]=1;
     node*tmp;
     tmp=graph_tra[v];
     while(tmp!=NULL)
     {
	  if(visited[tmp->data]==0)
	  {
	       dfs(tmp->data);
	  }
	  tmp=tmp->next;
     }
}


void DFS(int v)
{
     ++time;
     node*tmp;
     tmp=graph[v];
     visited[v]=1;
     while(tmp!=NULL)
     {
	  if(visited[tmp->data]==0)
	  {
	       DFS(tmp->data);
	  }
	  tmp=tmp->next;
     }

     finish[kk].time=++time;
     finish[kk].v=v;
     kk++;

}
