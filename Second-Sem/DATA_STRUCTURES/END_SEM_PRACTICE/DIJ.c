#include<stdio.h>
#include<stdlib.h>
typedef struct grap
{
     int data;
     int wt;
     struct grap*next;
}
node;


int visited[10000]={0};
node*graph[10000]={NULL};	
int distance[10000]={0};
int cmin=0;
node minheap[10000];
void sd_min();


//	FUNCTIONS

void insert_min(node x)
{
     int i,p;
     node temp;
     cmin++;
     minheap[cmin]=x;
     i=cmin;
     while(i>1)
     {
	  p=i/2;
	  if(minheap[p].wt>minheap[i].wt)
	  {
	       temp=minheap[i];
	       minheap[i]=minheap[p];
	       minheap[p]=temp;
	  }
	  else
	       break;
	  i=p;
     }
}

int del_min()
{
     int min;
     min=minheap[1].data;
     minheap[1]=minheap[cmin];
     cmin--;
     sd_min();
     return min;
}

void sd_min()
{
     int i=1;
     int min;
     node temp;
     while(i<=cmin/2 && (minheap[i].wt>minheap[2*i].wt||minheap[i].wt>minheap[2*i+1].wt))
     {
	  min=minheap[2*i].wt<minheap[2*i+1].wt?2*i:2*i+1;
	  temp=minheap[i];
	  minheap[i]=minheap[min];
	  minheap[min]=temp;
	  i=min;
     }
}



void DIJ(int s,int e)
{
     int w;
     node item;
     visited[s]=1;
     node*tmp;
     tmp=graph[s];
     while(tmp!=NULL)
     {
	  w=tmp->data;
	  if(visited[w]!=1&&distance[w]>distance[s]+tmp->wt)
	  {
	       distance[w]=distance[s]+tmp->wt;
	       item.wt=distance[w];
	       item.data=w;

	       insert_min(item);
	  }
	  tmp=tmp->next;
     }

     s=del_min();
     visited[s]=1;
     if(cmin==0||s==e)
	  return;
     DIJ(s,e);
}



int main()
{
     int m,n,u,v,w;
     int i,j;
     int a,b;
     node*new;

     scanf("%d%d",&n,&m);
     while(m--)
     {
	  scanf("%d%d%d",&u,&v,&w);
	  new=(node*)malloc(sizeof(node));
	  new->data=v;
	  new->wt=w;

	  new->next=graph[u];
	  graph[u]=new;
     }

     scanf("%d%d",&a,&b);

     for(i=0;i<=n;i++)
	  distance[i]=10000;

     distance[a]=0;
   
     DIJ(a,b);

     printf("%d\n",distance[b]);
}
