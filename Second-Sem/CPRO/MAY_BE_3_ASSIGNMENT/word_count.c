#include<stdio.h>
int main()
{
	int FLAG=0,co,num=0,c,p,i,m,k,max,j,count[11];
	for(i=0;i<11;i++)
		count[i]=0;
	while((c=getchar())!=EOF)
	{
		if(c=='\n'||c=='\t'||c==' ')
		{
			FLAG=0;
		}
		else
		{
				FLAG=1;
		}
		if(FLAG==0)
		{
			num=0;
			count[co]++;
		}
		if(FLAG==1)
		{
			num++;
		}
		co=num;
	}
	for(i=1;i<10;i++)
	{
	        printf("NUMBER OF WORDS WITH %d CHARACTERS=%d",i,count[i]);
		printf("\n");
	}
	printf("\n\n\n");
	printf("PRINTING THE HISTOGRAM:-");
		for(i=1;i<11;i++)
		{
			m=count[i];
			printf("WORDS %d = ",i);
			for(p=1;p<=m;p++)
			{
				printf("*");
			}
			printf("\n");
		}
	printf("\n\n\n PRINTING VERTICAL HISTOGRAM");
	
	/*for(i=1;i<11;i++)
	{
		for(j=1;j<11;j++)
		{
			if(count[i]>=count[j]);
			{
				max=count[i];
			}
		}
	}*/
	max=5;
	printf("%d",max);

	int histogram[5][11];
	for(i=1;i<11;i++)
	{
			for(k=1;k<count[i];k++)
			histogram[11-k][i]='*';
	
	}
	for(i=1;i<max;i++)
	{
		for(j=1;j<11;j++)
		{
			printf(" %c",histogram[i][j]);
		}
	}







	return 0;


}






