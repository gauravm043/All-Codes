#include<stdio.h>
#include<string.h>
typedef struct ll
{
     int x;
     int y;
}
node;
void print(node j[],int y);
char str[1000000];
node f[1000000];
int comp(void const*a,void const*b)
{
     node*p=(node*)a;
     node*q=(node*)b;
     if(p->x!=q->x)
	  return p->x-q->x;
     else
	  return p->y-q->y;
}
int main()
{
     int t,n,i,num,count;
     int can1,can2,a,b,c;
     scanf("%d",&t);
     while(t!=0)
     {
	  a=b=c=0;
	  f[0].x=0;
	  f[0].y=0;
	  num=1,count=0,i=0;
	  scanf("%s",str);
	  n=strlen(str);
	  for(i=1;i<=n;i++)
	  {
	       if(str[i-1]=='a')
		    a++;
	       else if(str[i-1]=='b')
		    b++;
	       else
		    c++;

	       f[i].x=a-b;
	       f[i].y=b-c;
	  }

	  n=i;
	  qsort(f,i,sizeof(node),comp);
	  print(f,n);
	  can1=f[0].x;
	  can2=f[0].y;
	  for(i=1;i<n;i++)
	  {
	       if(f[i].x==can1&&f[i].y==can2)
	       {
		    num++;
	       }
	       else
	       {
		    count+=num*(num-1)/2;
		    num=1;
		    can1=f[i].x;
		    can2=f[i].y;
	       }
	  }
	  if(f[n-1].x==can1&&f[n-1].y==can2)
	  {
	       count+=(num*(num-1)/2);
	  }
	  printf("%d\n",count);
	  t--;
     }
     return 0;
}

void print(node f[],int n)
{
     int i;
     for(i=0;i<n;i++)
	  printf("x=%d y=%d\n",f[i].x,f[i].y);
     printf("\n");
}
