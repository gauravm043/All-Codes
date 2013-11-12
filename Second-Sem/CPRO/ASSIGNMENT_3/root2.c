#include<stdio.h>
#include<math.h>
float fun(int n,float x,int array[*]);
int main()
{
	int t,i,n;
	float x1[2],x2,fx_x1=0,fx_x2=0;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		int values[n];
		for(i=n;i>=0;i--)
			scanf("%d",&values[i]);
	        scanf("%f%f",&x1[0],&x2);
                lb:
		fx_x1=fun(n,x1[0],values);
		fx_x2=fun(n,x2,values);
		
		
		
		if(fx_x1>0)
			c=x1;
		if(fx_x1<0&&fx_x2>0)
		{
			x1[0]=(x1[0]+x2)/2;
			goto lb;
		}

		if(fx_x1<=0.001)
		{
			printf("%f",x1);
		}


			
		
		
		
	/*	printf("%f%f",fx_x1,fx_x2);*/

	t--;
	}
return 0;
}
float fun(int n,float x,int values[])
{
	int fx=0,i;
	for(i=n;i>=0;i--)
	{
		fx+=values[i]*pow(x,i);
	}
	return fx;
}




