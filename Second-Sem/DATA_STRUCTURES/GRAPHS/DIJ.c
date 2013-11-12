#include<stdio.h>
#include<stdlib.h>
typedef struct list
{
     int data;
     int wt;
     struct list*next;
}
node;

int distance[10000];
node*arr[1000]={NULL};
void print(int r);
void DFS(int v);
node heap[10000];
int visited[1000]={0};
void DIJ(int q);
void insert(int r,int e);
int deletemin();
void SD();
int k,s,e;

int main()
{
     int n,i;
     int num,a,b,c;
     int h,j;

     for(i=0;i<100;i++)
	  distance[i]=1000;




     scanf("%d",&n);
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

 //    printf("GRAPH IS : --> \n");
   //  print(n);
     scanf("%d%d",&s,&e);
     distance[s]=0;
     DIJ(s);
     printf("SHORTEST DISTANCE--->>>%d\n",distance[e]);
     return 0;
}

void DIJ(int v)
{
 
//     printf("vert--%d\n",v);
     node*tmp;
     tmp=arr[v];
  //   if(k==0)
//	  return;

     while(tmp!=NULL)
     {
	  if(distance[tmp->data]>distance[v]+tmp->wt)
	  {
	       distance[tmp->data]=distance[v]+tmp->wt;
	  //     printf("of vertex  %d     distance is %d     ",tmp->data,distance[tmp->data]);
	       insert(distance[tmp->data],tmp->data);
	  }
	  tmp=tmp->next;
     }

     if(k==0)
	  return;

 
     visited[v]=1;
     if(v==e)
	  return;

     v=deletemin();
     
     DIJ(v);
}

void  insert(int d,int v)
{
     int i,tmp1,tmp2;
     int p,done;
     k=k+1;
    // printf("k--->>%d\n",k);
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
     printf("del--->>>%d\n",min);
     return min;
}

void SD()
{
     int i=1,index;
     int tmp1,tmp2;
     while(i<=k/2 && (heap[i].wt>heap[2*i].wt||heap[i].wt>heap[2*i+1].wt))
     {
	  index=heap[2*i].wt>heap[2*i+1].wt?2*i:2*i+1;
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


void print(int n)
{
     int i;
     for(i=0;i<n;i++)
     {
	  if(arr[i]!=NULL)
	  {
	       node*tmp;
	       tmp=arr[i];
	       while(tmp!=NULL)
	       {
		    printf("--->>>%d      (%d)  ",tmp->data,tmp->wt);
		    tmp=tmp->next;
	       }
	       printf("\n");
	  }
     }
}
