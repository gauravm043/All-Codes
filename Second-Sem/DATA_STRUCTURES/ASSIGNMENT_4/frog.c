#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct list
{
     int a;
     int b;
}
node;

void DIJ(int a);
node stone[201];
double distance[201][201];
int visited[201];
double dist[201];
int count=0;


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
	       dist[i]=0;
	       scanf("%d%d",&stone[i].a,&stone[i].b);
	  }

	  /* CALCULATING DISTANCES */

	  for(i=1;i<=n;i++)
	  {
	       for(j=1;j<=i;j++)
	       {
		    d=sqrt(pow(stone[i].a-stone[j].a,2)+pow(stone[i].b-stone[j].b,2));
		    distance[i][j]=d;
		    distance[j][i]=d;
		    //newrintf("%f\n",dist);
	       }
	  }

	  /* DIJKSTRA */
	  DIJ(n);

     }
}

void DIJ(n)
{
     int i,j,new;
     double min,max;
     for(i=1;i<=n;i++)
     {
	  dist[i]=distance[1][i];
     }
     visited[1]=1;
     for(i=2;i<=n;i++)
     {
	  min=1000000;
	  for(j=1;j<=n;j++)
	  {
	       if(visited[j]==0&&min>dist[j])
	       {
		    min=dist[j];
		    new=j;
	       }
	  }
	  visited[new]=1;
	  for(j=1;j<=n;j++)
	  {
	       max=dist[new]>distance[new][j]?dist[new]:distance[new][j];
	       dist[j]=dist[j]<max?dist[j]:max;
	  }
     }

     printf("Scenario#%d\n",++count);
     printf("Frog Distance=");
     printf("%0.3lf\n\n",dist[2]);
}
