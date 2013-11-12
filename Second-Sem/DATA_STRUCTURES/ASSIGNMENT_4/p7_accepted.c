#include<stdio.h>
#include<stdlib.h>

int maxheap[1000030];
int minheap[1000030];
int cmax;
int cmin;

/* FUNCTIONS USED ARE */
void insert_min(int y);
void insert_max(int y);
int del_min();
int del_max();

/* DECLARATIONS END HERE */

int main()
{
     int test;
     scanf("%d",&test);
     while(test--)
     {
     int t,i,n,a;
     int days,item,b;
     int visited[1000007]={0};
     long long int PRIZE=0;
     cmax=cmin=0;
     scanf("%d",&days);
     for(i=0;i<days;i++)
     {  
	  scanf("%d",&n);
	  while(n--)
	  {
	       scanf("%d",&item);
	       insert_max(item);
	       insert_min(item);
	       visited[item]++;
	  }

	  /*  CALCULATING  PRIZE MONEY */

	  a=del_max();
	  b=del_min();
	  while(visited[a]==0&&cmax>0)
	  {
	       a=del_max();
	  }
	  while(visited[b]==0&&cmin>0)
	  {
	       b=del_min();
	  }
	  visited[a]--;
	  visited[b]--;
	  PRIZE+=a-b;
     }

     printf("%lld\n",PRIZE);
     }
     return 0;
}

void insert_min(int d)
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

void insert_max(int d)
{
     cmax++;
     maxheap[cmax]=d;
     int i,tmp,p;
     i=cmax;
     while(i>1)
     {
	  p=i/2;
	  if(p>0&&maxheap[p]<maxheap[i])
	  {
	       tmp=maxheap[i];
	       maxheap[i]=maxheap[p];
	       maxheap[p]=tmp;
	       i=p;
	  }
	  else
	       break;
     }
}

int del_min()
{
     int min;
     min=minheap[1];
     minheap[1]=minheap[cmin];
     cmin--;
     int i=1;
     int mi;
     int tmp;
     while(i<=cmin/2 &&(minheap[i]>minheap[2*i]||minheap[i]>minheap[2*i+1]))
     {
	  mi=minheap[2*i]<=minheap[2*i+1]?2*i:2*i+1;
	  tmp=minheap[i];
	  minheap[i]=minheap[mi];
	  minheap[mi]=tmp;
	  i=mi;
     }
     return min;
}

int del_max()
{
     int max;
     max=maxheap[1];
     maxheap[1]=maxheap[cmax];
     cmax--;
     int i=1;
     int ma;
     int tmp;
     while(i<=cmax/2 &&(maxheap[i]<maxheap[2*i]||maxheap[i]<maxheap[2*i+1]))
     {
	  ma=maxheap[2*i]>=maxheap[2*i+1]?2*i:2*i+1;
	  tmp=maxheap[i];
	  maxheap[i]=maxheap[ma];
	  maxheap[ma]=tmp;
	  i=ma;
     }
     return max;
}

