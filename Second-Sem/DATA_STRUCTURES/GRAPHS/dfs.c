#include<stdio.h>
#include<stdlib.h>
typedef struct node{
     int data;
     struct node*next;
}node;
typedef struct vertex{
     int start;
     int end;
}vertex;
vertex stack[1000];
int visited[1000],k;
node*g[1000];
void dfs(int c)
{
     node *v=g[c];
     visited[c]=1;
     node*temp=v;
     stack[c].start=k++;
     while(v!=NULL)
     {
	  if(visited[v->data]==0)
	  {
	       visited[v->data]=1;
	       int p=v->data;
	       dfs(p);
	  }
	  v=v->next;
     }
     stack[c].end=k++;
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
     dfs(0);
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
     for(i=0;i<n;i++)
	  printf("node :  %d  start :  %d    end : %d   \n",i,stack[i].start,stack[i].end);
     printf("\n\n");
     return 0;
}















