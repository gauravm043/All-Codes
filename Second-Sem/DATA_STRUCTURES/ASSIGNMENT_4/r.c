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
void sd_min();
void sd_max();

/* DECLARATIONS END HERE */

int main()
{
     int t,i,n,mm,a;
     int days,item,b;
     int visited[100007]={0};
     int PRIZE=0;
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
	  for(mm=1;mm<=cmax;mm++)
	  {
	       printf("%d     %d\n",maxheap[mm],minheap[mm]);
	  }
/*	  while(visited[a]==0)
	  {
	       a=del_max();
	  }
	  while(visited[b]==0)
	  {
	       b=del_min();
	  }
	  visited[a]--;
	  visited[b]--;
	  PRIZE+=a-b;*/
     }

     printf("%d\n",PRIZE);
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
     sd_min();
     return min;
}

int del_max()
{
     int max;
     max=maxheap[1];
     maxheap[1]=maxheap[cmax];
     cmax--;
     sd_max();
     return max;
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
void sd_max()
{
     int i=1;
     int max;
     int tmp;
     while(i<=cmax/2 &&(maxheap[i]<maxheap[2*i]||maxheap[i]<maxheap[2*i+1]))
     {
	  max=maxheap[2*i]>=maxheap[2*i+1]?2*i:2*i+1;
	  tmp=maxheap[i];
	  maxheap[i]=maxheap[max];
	  maxheap[max]=tmp;
	  i=max;
     }
}
