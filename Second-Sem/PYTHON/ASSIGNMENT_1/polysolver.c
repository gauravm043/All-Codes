#include<stdio.h>
#include<math.h>
int main()
{
     	int a,b,c,d;
	float x;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	for(x=5;x<6;x=x+0.1)
	{
	     double g=a*x*x*x+b*x*x+c*x+d;
	    printf("g=%lf x=%lf\n",g,x);
	     if(g==0)
		  printf("%lf\n",x);
	}
	
	  return 0;
}
