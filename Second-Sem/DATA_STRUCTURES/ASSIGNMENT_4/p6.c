#include<stdio.h>
#define MAX 10000
#include<stdlib.h>
typedef struct m
{
     int data;
     struct m*next;
}
node;


int TIMES=0;
int saurabh=0;
int gaurav=0;
void print();
void BFS(int a,int b);
int prime[1062];
node*arr[10000]={NULL};
int seive[MAX];
int distance[10000];
int queue[1000000];
int visited[10000];

int main()
{
     /* SIEVE */

     int k=0,r1,r2,a,b;
     int i,j,cnt;

     for(i=0;i<MAX;i++)
	  seive[i]=i;
     for(i=2;i<MAX;i=i+2)
	  seive[i]=-1;
     for(i=3;i<MAX;i++)
     {
	  if(seive[i]!=-1)
	  {
	       if(i>1000)
		    prime[k++]=i;
	       for(j=i;j<MAX;j=j+i)
		    seive[j]=-1;
	  }
     }

     /* GENERATING GRAPH OF PRIMES */

     for(i=0;i<k;i++)
     {

	  for(j=0;j<k;j++)
	  {
	       a=prime[i];
	       b=prime[j];
	       cnt=0;
	       while(a!=0)
	       {
		    r1=a%10;
		    r2=b%10;
		    if(r1==r2)
			 cnt++;
		    a=a/10;
		    b=b/10;
	       }

	       if(cnt==3)
	       {
		    node*new;
		    new=(node*)malloc(sizeof(node));
		    new->data=prime[j];
		    if(arr[prime[i]]==NULL)
		    {
			 new->next=NULL;
			 arr[prime[i]]=new;
		    }
		    else
		    {
			 new->next=arr[prime[i]];
			 arr[prime[i]]=new;
		    }
	       }
	  }
     }

     /* ORIGINAL PROBLEM*/
          print();
     int test;
     scanf("%d",&test);

     while(test--)
     {
	  for(i=0;i<10000;i++)
	  {
	       visited[i]=0;
	       distance[i]=10000;
	  }
	  int s;
	  int e;
	  saurabh=0;
	  gaurav=0;
	  scanf("%d%d",&s,&e);
	  if(s==e)
	  {
	       printf("0\n");
	       continue;
	  }
	  BFS(s,e);
	  printf("%d\n",distance[e]);
     }

     return 0;
}

void print()
{
     int i,f;
     node*tmp;
     for(i=1033;i<1034;i++)
     {
	  f=0;
	  tmp=arr[i];
	  while(tmp!=NULL)
	  {
	       printf("---->>%d(**%d**)",tmp->data,i);
	       tmp=tmp->next;
	       f=1;
	  }
	  if(f==1)
	       printf("\n");
     }
}

void BFS(int s,int e)
{
     int p;
     queue[gaurav++]=s;
     distance[s]=0;
     while(gaurav!=saurabh)
     {
	  node*tmp;
	  tmp=arr[queue[saurabh]];
	  p=queue[saurabh];
	  while(tmp!=NULL)
	  {
	       if(visited[tmp->data]==0)
	       {
		    distance[tmp->data]=distance[p]+1;
		    visited[tmp->data]=1;
		    if(tmp->data==e)
			 return;
		    queue[gaurav++]=tmp->data;
	       }
	       tmp=tmp->next;
	  }
	  saurabh++;
     }

     return;
}
