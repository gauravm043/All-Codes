#include<stdio.h>
#include<math.h>


int calculate(int lanes[][501])
{
     int i,ans=500;
     int x=0;
     for(i=1;i<=500;i++)
     {
	  x=0;
	  while(x!=9)
	  {
	       if(lanes[x][i]==-1&&lanes[x+1][i]==-1)
	       {
		    break;
	       }
	       x++;
	  }
	  if(x!=9)
	       ans--;
     }
     return ans;
}


	  


int main()
{
     int test,i,bub;
     int s,e,l,ans;
     scanf("%d",&test);
     while(test--)
     {
	  int lanes[10][501]={(0,0)};
	  scanf("%d",&bub);
	  while(bub--)
	  {
	  scanf("%d%d%d",&s,&e,&l);
	  for(i=s;i<=e;i++)
	       lanes[l][i]=-1;
	  }
	  ans=calculate(lanes);
	  printf("%d\n",ans);
     }
     return 0;
}
