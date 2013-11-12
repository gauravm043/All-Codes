#include<stdio.h>
int main()
{
	long int c,track,t,i,transfer,n,product=1;
	scanf("%ld",&t);
	while(t!=0)
	{
		long int FACTORIAL[300]={0};;
		FACTORIAL[0]=1;
		scanf("%ld",&n);
		track=1;
		while(track<=n)
		{
			product=0;
			transfer=0;
			i=0;
		
			while(i!=299)
			{
                        product=track*FACTORIAL[i];
			FACTORIAL[i]=(transfer+product%10)%10;
			transfer=(product+transfer)/10;
	                i++;
			}
			track++;
		}
		int check=0;
		for(i=299;i>=0;i--)
		{
			if(check==0)
			{
			if(FACTORIAL[i]!=0)
			{
				check=1;
				/*printf("%ld",FACTORIAL[i]);*/
			}
			}

                 if(check==1)
		 {
		
		printf("%ld",FACTORIAL[i]);
		 }
		}
		printf("\n");

	/*	for(m=1;m<10;m++)
			m=m*m;*/
		t--;
	}
	return 0;
}









