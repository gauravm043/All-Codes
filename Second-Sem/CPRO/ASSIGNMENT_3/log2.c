#include<stdio.h>
#include<math.h>
int main()
{
	float  test,arg,c,inc,s,i,b,a;	
	scanf("%f",&test);
	for(c=1;c<10;c++)
		c=c*c;
	while(test!=0)
	{
		scanf("%f",&arg);
			
				inc=0.693147;
				s=0;
				b=arg;
			
		
			while(fabs(inc)>0.00001)
			{
				b=b*b;
				
				if(b<2)
				{
					inc=0.5*inc;
				
				}
				if(b>=2)
				{
					s=s+inc/2;
					inc=inc/2;
					
				        b=b/2;
				
				}
			}
		
		printf("%0.3f\n",s);
		test--;
	}
	return 0;
}



