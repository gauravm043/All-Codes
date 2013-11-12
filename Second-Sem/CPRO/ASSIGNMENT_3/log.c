#include<stdio.h>
int main()
{
	float i=1,t,term,sum,x,y;
	scanf("%f",&t);
	while(t!=0)
	{
		scanf("%f",&y);
		sum=0;
		x=(y-1);
		term=x;
		i=1;
		while(term>0.000001)
		{
			sum+=term;
			term=term*(-1)*x*i/(i+1);
			i++;
		}
		printf("%0.3f\n",sum);
		t--;
	}
	return 0;
}




