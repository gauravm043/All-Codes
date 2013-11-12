#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node*next;
}node;
int visited[1000],k,start=0,end=0;
int indeg[1000]={0};
node*g[1000];
int queue[1000];
int ans[1000];
void bfs(int c)
{
     queue[start]=c;
     end++;
     while(start!=end)
     {
	  node *v=g[queue[start]];
	  while(v!=NULL)
	  {
	       indeg[v->data]--;
	       if(indeg[v->data]==0)
	       {
		    queue[end]=v->data;
		    end++;
	       }
	       v=v->next;
	  }
	  ans[k++]=queue[start];
	  printf("ans : %d \n",queue[start]);
	  start++;
     }
}
int main()
{
     int n,i,j,k,z,t;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
	  scanf("%d",&z);
	  while(z--)
	  {
	       scanf("%d",&t);
	       indeg[t]++;
	       node*np=(node*)malloc(sizeof(node));
	       np->data=t;
	       np->next=NULL;
	       if(g[i]==NULL)
		    g[i]=np;
	       else
	       {
		    node*temp=g[i];
		    g[i]=np;
		    g[i]->next=temp;
	       }
	  }
     }
     bfs(0);
     for(i=0;i<n;i++)
     {
	  node*temp=g[i];
	  while(temp!=NULL)
	  {
	       printf("%d ",temp->data);
	       temp=temp->next;
	  }
	  printf("\n");
     }
     printf("\n");
     printf("ans\n");
     for(i=0;i<k;i++)
	  printf("%d ",ans[i]);
     printf("\n");
     return 0;
}















