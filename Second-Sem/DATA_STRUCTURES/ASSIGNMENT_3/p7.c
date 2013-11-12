#include<stdio.h>
typedef struct p
{
     int a;
     int b;
}
r;
r point[2000002];
void print(int y);

int main()
{
     int test,i,j,x,y;
     int m,n,num,pos,ans;
     scanf("%d",&test);
     while(test--)
     {
	  int s=0,f=0;
	  scanf("%d%d",&m,&n);
	  for(i=0;i<m;i++)
	  {
	       scanf("%d",&num);
	       if(num!=0)
	       {
		    f=1;
		    for(j=0;j<num;j++)
		    {
			 scanf("%d",&pos);
			 point[s].a=i;
			 point[s].b=pos;
			 s++;
		    }
	       }
	  }


	  int q,w,r,c,min=100000000;
	  scanf("%d%d",&q,&w);
	  if(f==0)
	  {
	       printf("-1 -1\n");
	       continue;
	  }

	  /* CALCULATING*/

	  for(i=0;i<s;i++)
	  {
	   
	       ans=abs(q-point[i].a)>abs(w-point[i].b)?abs(q-point[i].a):abs(w-point[i].b);

	       if(ans<min)
	       {
		    min=ans;
		    r=point[i].a;
		    c=point[i].b;
	       }
	       if(ans==min)
	       {
		    if(point[i].a>r)
			 r=point[i].a;
		    if(point[i].b>c)
			 c=point[i].b;

	       }
	  }
	  printf("%d %d\n",r,c);
     }
     return 0;
}
