#include<stdio.h>
int ar[100]={0};
int inp[100];
int final[100];
int main()
{
	int i,kk,tru=1;
	int k=0,n,hh,gaurav,test,j,small,temp,fd,dh,trans,gh=1;
//	scanf("%d",&test);
//	while(test!=0)
//	{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&inp[i]);
/*	deletion of multiple elements*/


        for(fd=1;fd<=n;fd++)
	{
		if(inp[fd]!=-1000)
		{
			trans=inp[fd];
			final[gh]=inp[fd];
			gh++;
		}

		for(kk=1;kk<=n;kk++)
		{
			if(trans==inp[kk])
				inp[kk]=-1000;
		}
	}

	/*for(i=1;i<=gh-1;i++)
		printf("%d",final[i]);

	printf("\n");*/
	
	
	
	/*sorting*/

	for(i=1;i<=gh-1;i++)
	{
		hh=i;
		small=final[i];
		
		for(j=i+1;j<=gh-1;j++)
		{
			if(final[j]<small)
			{
				small=final[j];
				hh=j;
			}
		}

			temp=final[i];
			final[i]=small;
			final[hh]=temp;
		
	}

/*	for(i=1;i<=gh-1;i++)
		printf("%d",final[i]);*/

      
	while(tru)
	{
		if(ar[k]==gh-1)
		{
			ar[k-1]=ar[k-1]+1;
			k--;
		}
		else
		{
			ar[k+1]=ar[k]+1;
			k++;
		}


		for(i=1;i<=k;i++)
		{
			gaurav=ar[i];
		        printf("%d ",final[gaurav]);
		}


                  if(k==0)
			break;

		  printf("\n");
	}

//	test--;
//	}
//	
	return 0;
}



		

