#include<stdio.h>
typedef struct list
{
     int col;
     int pos[1000];
}
r;
r row[100000];
void print(int y);
int main()
{
     int test,a,b;
     int m,n,x;
     int i,j,y;
     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d%d",&m,&n);
	  for(i=0;i<m;i++)
	  {
	       scanf("%d",&row[i].col);
	       if(row[i].col!=0)
		    for(j=0;j<row[i].col;j++)
			 scanf("%d",&row[i].pos[j]);
	  }

	  scanf("%d%d",&a,&b);
	  x=a;
	  y=b;


	  /* CHECKING DISTANCE */
	  int ans=0,min=1000000;
	  int r=0,c=0;
	  //print(m);

	  for(i=0;i<m;i++)
	  {
	       if(row[i].col!=0)
	       {
		    for(j=0;j<row[i].col;j++)
		    {
			 ans=0;
			 x=a;
			 y=b;
			 while(x!=i&&y!=row[i].pos[j])
			 {
			      ans++;
			      if(y<row[i].pos[j])
			      {
				   y++;
				   if(x<i)
					x++;
				   else
					x--;
			      }
			      else
			      {
				   y--;
				   if(x<i)
					x++;
				   else
					x--;
			      }
			 }
			 while(x!=i)
			 {
			      ans++;
			      if(x<i)
				   x++;
			      else
				   x--;
			 }
			 while(y!=row[i].pos[j])
			 {
			      ans++;
			      if(y<row[i].pos[j])
				   y++;
			      else
				   y--;
			 }

			 if(ans<min)
			 {
			      min=ans;
			      r=i;
			      c=row[i].pos[j];
			 }
			 if(ans==min)
			 {
			      if(i>r)
				   r=i;
			      if(row[i].pos[j]>c)
				   c=row[i].pos[j];

			 }
		    
		//    printf("steps-->>%d    ",ans);
		    }
		   // printf("\n");
	       }
	  }
		    //printf("final answer---->>   %d %d\n",r,c);
	  printf("%d %d\n",r,c);
     }
     return 0;
}

void print(int m)
{
     int i,j;
     for(i=0;i<m;i++)
     {
	  if(row[i].col!=0)
	       for(j=0;j<row[i].col;j++)
		    printf("%d  ",row[i].pos[j]);
	  printf("\n");
     }
}
