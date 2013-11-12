#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
     int v;
     struct list*next;
}
node;

/* Declarations */
int cmin=0;
int minheap[10000];

/* Functions */
void insert(int d)
{
     cmin++;
     minheap[cmin]=d;
     int i,tmp,p;
     i=cmin;
     while(i>1)
     {
	  p=i/2;
	  if(p>0&&minheap[p]>minheap[i])
	  {
	       tmp=minheap[i];
	       minheap[i]=minheap[p];
	       minheap[p]=tmp;
	       i=p;
	  }
	  else
	       break;
     }
}

void sd_min()
{
     int i=1;
     int min;
     int tmp;
     while(i<=cmin/2 &&(minheap[i]>minheap[2*i]||minheap[i]>minheap[2*i+1]))
     {
	  min=minheap[2*i]<=minheap[2*i+1]?2*i:2*i+1;
	  tmp=minheap[i];
	  minheap[i]=minheap[min];
	  minheap[min]=tmp;
	  i=min;
     }
}
int delete_min()
{
     int min;
     min=minheap[1];
     minheap[1]=minheap[cmin];
     cmin--;
     sd_min();
     return min;
}

int answer[201];


int main()
{
     int test;
     int u,v,i;
     int m,n;
     node*new;
     while(1)
     {
	  cmin=0;
	  int cnt=0;
	  node*arr[201]={NULL};
	  int indegree[201]={0};
	  scanf("%d%d",&m,&n);
	  if(m==0&&n==0)
	       return 0;
	  while(n--)
	  {
	       scanf("%d%d",&u,&v);
	       indegree[v]++;
	       new=(node*)malloc(sizeof(node));
	       new->v=v;
	       if(arr[u]==NULL)
	       {
		    new->next=NULL;
		    arr[u]=new;
	       }
	       else
	       {
		    new->next=arr[u];
		    arr[u]=new;
	       }
	  }

	  for(i=1;i<=m;i++)
	  {
	       if(indegree[i]==0)
	       {
		    insert(i);
	       }
	  }

	  node*tmp;
	  int kk=0;

	  while(cmin!=0)
	  {
	       cnt++;
	       v=delete_min();
	       answer[kk++]=v;

	       tmp=arr[v];
	       while(tmp!=NULL)
	       {
		    indegree[tmp->v]--;
		    if(indegree[tmp->v]==0)
		    {
			 insert(tmp->v);
		    }
		    tmp=tmp->next;
	       }
	  }
	  if(cnt!=m)
	       printf("NOT POSSIBLE");
	  else
	       for(i=0;i<kk;i++)
	       {
		    printf("%d ",answer[i]);
	       }
	  printf("\n");
     }
}
