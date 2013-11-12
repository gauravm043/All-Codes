#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
     int data;
     int wt;
     struct list*next;
}
node;

int distance[100001];
node*arr[100001]={NULL};
node heap[200001];
int visited[100001]={0};
void DIJ(int q);
void insert(int r,int e);
int deletemin();
void SD();
int k,e;

int main()
{
     int n,i,s;
     int num,a,b,c;
     int h,j;
     int test;
     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d",&n);

	  for(i=1;i<=n;i++)
	  {
	       distance[i]=10000000;
	       arr[i]=NULL;
	       visited[i]=0;
	  }

	 
	  scanf("%d",&h);
	  for(j=0;j<h;j++)
	  {
	       scanf("%d%d%d",&a,&b,&c);
	       node*new;
	       new=(node*)malloc(sizeof(node));
	       new->data=b;
	       new->wt=c;
	       if(arr[a]==NULL)
	       {
		    arr[a]=new;
		    new->next=NULL;
	       }
	       else
	       {
		    new->next=arr[a];
		    arr[a]=new;
	       }
	  }

	  k=0;
	  scanf("%d%d",&s,&e);

	  distance[s]=0;
	  DIJ(s);
	  if(distance[e]!=10000000)
	       printf("%d\n",distance[e]);
	  else
	       printf("NO\n");
     }
     return 0;
}

void DIJ(int v)
{

     node*tmp;
     tmp=arr[v];

     while(tmp!=NULL)
     {
	  if(distance[tmp->data]>distance[v]+tmp->wt)
	  {
	       distance[tmp->data]=distance[v]+tmp->wt;
	       insert(distance[tmp->data],tmp->data);
	  }
	  tmp=tmp->next;
     }

     visited[v]=1;
     if(v==e||k==0)
	  return;

     v=deletemin();
//     printf("---->>>%d\n",v);

     DIJ(v);
}

void  insert(int d,int v)
{
     int i,tmp1,tmp2;
     int p,done;
     k=k+1;
     heap[k].data=v;
     heap[k].wt=d;          //ITS  THE DISTANCE
     i=k;
     done=0;
     while(i!=1&&done!=1)
     {
	  p=i/2;
	  if(heap[p].wt>heap[i].wt)
	  {
	       tmp1=heap[p].wt;
	       tmp2=heap[p].data;
	       heap[p].wt=heap[i].wt;
	       heap[p].data=heap[i].data;
	       heap[i].wt=tmp1;
	       heap[i].data=tmp2;
	       i=p;
	  }
	  else
	       done=1;
     }
}


int deletemin()
{
     int min;
     min=heap[1].data;
     heap[1].wt=heap[k].wt;
     heap[1].data=heap[k].data;
     k=k-1;
     SD();
     return min;
}

void SD()
{
     int i=1,index;
     int tmp1,tmp2;
     while(i<=k/2 && (heap[i].wt>heap[2*i].wt||heap[i].wt>heap[2*i+1].wt))
     {
	  index=heap[2*i].wt<heap[2*i+1].wt?2*i:2*i+1;
	  /* SWAP */

	  tmp1=heap[i].wt;
	  tmp2=heap[i].data;
	  heap[i].wt=heap[index].wt;
	  heap[i].data=heap[index].data;
	  heap[index].wt=tmp1;
	  heap[index].data=tmp2;

	  i=index;
     }
}
