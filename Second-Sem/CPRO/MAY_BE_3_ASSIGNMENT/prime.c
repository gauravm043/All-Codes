#include<stdio.h>
#define eps 100000000
int main()
{
	int num,wish,track=0,i,j,check;
	printf("ENTER HOW MANY PRIME NUMBERS YOU WANT TO SEE=\n");
	scanf("%d",&wish);
	if(wish==1)
	{
		printf("2\n");
		return 0;
	}
	else
		printf("2\n");

         for(i=3;i<eps;i++)
	{
		check=1;
		for(j=2;j<i;j++)
		{
			if(i%j==0)
			{
		                check=0;
				goto lb;
			}

		}
                lb:
		if(check!=0)
		{
			track++;
			printf("%d\n",i);
		}
		if(track==(wish-1))
			break;
	}
	return 0;
}


