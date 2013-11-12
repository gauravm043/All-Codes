#include<stdio.h>
#include<math.h>
float fun(int n,float x,int array[*]);
int main()
{
	int t,i,n;
	float f,l,x1,x2,m,fx_m=0;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		int values[n];
		for(i=n;i>=0;i--)
			scanf("%d",&values[i]);
	        scanf("%f %f",&x1,&x2);
                f=x1,l=x2;
                m=(f+l)/2;
                fx_m=0;
                lb:
		fx_m=fun(n,m,values);
		if(fabs(fx_m)>=0.001)
		{
		if(fx_m<0)
		{
			f=m;
			m=(f+l)/2;
			goto lb;
		}

		if(fx_m>0)
		{
			l=m;
			m=(f+l)/2;
			goto lb;
		}
		}
		printf("%0.3f\n",m);

	t--;
	}
return 0;
}
float fun(int n,float x,int values[])
{
	float fx=0;
	int i;
	for(i=n;i>=0;i--)
	{
		fx+=values[i]*pow(x,i);
	}
	return fx;
}




