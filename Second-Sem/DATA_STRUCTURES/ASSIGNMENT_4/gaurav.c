#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct list
{
     int a;
     int b;
}
node;
typedef struct a
{
     double dis;
     int data;
}
s;

s heap[100000];
void DIJ(int a);
node stone[201];
double distance[201][201];
int visited[201];
double dist[201];
int count=0;
int k=0;
void insert();
int deletemin();
void SD();


int main()
{
     int test;
     int n=1;
     while(1)
     {
	  int i,j;
	  double d;
	  scanf("%d",&n);

	  if(n==0)
	       return 0;

	  /* INPUTTING THE STONES */

	  for(i=1;i<=n;i++)
	  {
	       visited[i]=0;
	       dist[i]=1000000;
	       scanf("%d%d",&stone[i].a,&stone[i].b);
	  }

	  /* CALCULATING DISTANCES */

	  for(i=1;i<=n;i++)
	  {
	       for(j=1;j<=n;j++)
	       {
		    d=sqrt(pow(stone[i].a-stone[j].a,2)+pow(stone[i].b-stone[j].b,2));
		    distance[i][j]=d;
		    distance[j][i]=d;
	//	    printf("%lf\n",d);
	       }
	  }

	  /* DIJKSTRA */
	  DIJ(n);

     }
}

void DIJ(n)
{
     double max=0;
     int i,j,new;
     int old;
     for(i=1;i<=n;i++)
     {
	  dist[i]=distance[1][i];
	  insert(dist[i],i);
     }
     visited[1]=1;
     old=1;
     for(i=2;i<=n;i++)
     {
	       new=deletemin();
	       if(visited[new]==1)
	       {
		   i=i-1;
		    continue;
	       }
	
	  if(max<distance[old][new])
	       max=distance[old][new];
	  printf("vertex-->>%d\n",new);
	  for(j=1;j<=n;j++)
	  {
	       if(dist[j]>dist[new]+distance[new][j]&&visited[j]!=1)
	       {
		    dist[j]=dist[new]+distance[new][j];
		    insert(distance[new][j],j);
	       }
	  }
	  visited[new]=1;
	//  if(new==2)
	  //     break;
     }
     if(max<distance[old][new])
	  max=distance[old][new];

     printf("Scenario#%d\n",++count);
     printf("Frog Distance=");
     printf("%0.3lf\n\n",max);
}

void  insert(double d,int v)
{
     int i,tmp1,tmp2;
     int p,done;
     k=k+1;
     heap[k].data=v;
     heap[k].dis=d;          //ITS  THE DISTANCE
     i=k;
     done=0;
     while(i!=1&&done!=1)
     {
	  p=i/2;
	  if(heap[p].dis>heap[i].dis)
	  {
	       tmp1=heap[p].dis;
	       tmp2=heap[p].data;
	       heap[p].dis=heap[i].dis;
	       heap[p].data=heap[i].data;
	       heap[i].dis=tmp1;
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
     heap[1].dis=heap[k].dis;
     heap[1].data=heap[k].data;
     k=k-1;
     SD();
     return min;
}

void SD()
{
     int i=1,index;
     int tmp1,tmp2;
     while(i<=k/2 && (heap[i].dis>heap[2*i].dis||heap[i].dis>heap[2*i+1].dis))
     {
	  index=heap[2*i].dis<heap[2*i+1].dis?2*i:2*i+1;
	  /* SWAP */

	  tmp1=heap[i].dis;
	  tmp2=heap[i].data;
	  heap[i].dis=heap[index].dis;
	  heap[i].data=heap[index].data;
	  heap[index].dis=tmp1;
	  heap[index].data=tmp2;

	  i=index;
     }
}
