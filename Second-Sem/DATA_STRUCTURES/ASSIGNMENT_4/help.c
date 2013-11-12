#include<stdio.h>
typedef struct m
{
     int a;
     int b;
     int c;
}
node;
int cmp(void const*a,void const*b)
{
     node*p=(node*)a;
     node*q=(node*)b;
     return p->c-q->c;
}
node arr[1000000];
int main()
{
     int a,b,i=0,c,size;
     int m,n,min,p=0;
     min=10000000;
     int pur[7]={0};

     scanf("%d%d",&m,&n);
     while(i<m)
     {
	  scanf("%d%d%d",&arr[i].a,&arr[i].b,&arr[i].c);
	  i++;
     }

     size=i;

     qsort(arr,i+1,sizeof(node),cmp);

     for(i=1;i<=size;i++)
     {
	  if(pur[arr[i].a]==0)
	  {
	       pur[arr[i].a]=1;
	       p=p+arr[i].b;
	       if(arr[i].c<min)
		    min=arr[i].c;
	  }
     }
     
     if(min!=10000000)
	  printf("%d",min);
     else
	  printf("0");
     return 0;
}
