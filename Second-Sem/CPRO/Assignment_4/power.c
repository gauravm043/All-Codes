#include<stdio.h>
void per(int lj[],int n,int f,int a[]);
int main()
{
	int n,j=0;
	int arr[5]={1,2,3,4,5};
	scanf("%d",&n);
	int l[10]={0};
	per(l,n,j,arr);
	return 0;
}


void per(int l[],int n,int j,int arr[])
{
	int i,k,m;
	for(i=0;i<n;i++)
	{
		if(l[i]==0)
		{
			
			for(m=0;m<n;m++)
				if(l[m]==1)
				printf("%d",arr[m]);
			printf("\n");
			l[i]=1;
			per(l,n,j+1,arr);
			l[i]=0;
		}
	}


	if(j==n)
	{
		for(k=0;k<n;k++)
			if(l[k]==1)
			printf("%d",arr[k]);
		printf("\n");
		return;
	}

	return;
}

