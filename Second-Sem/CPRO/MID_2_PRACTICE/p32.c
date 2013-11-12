#include<stdio.h>
#include<math.h>
int main()
{
	int i,j,ch,n,check,m;
	int arr[100];
	printf("NUMBER OF ELEMENTS=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}


	ch=pow(2,n);
	check=ch-1;
	while(check!=0)
	{
		//printf("gg");

			m=0;
			for(j=check;j!=0;j=j>>1)
			{
				if((j&1)==1)
				{
					printf("%d  ",arr[n-m-1]);
				}
				m++;
			}
			printf("\n");
		check--;
	}


	return 0;
}





