#include<stdio.h>
int check=0,arr[100];
void sort(int a[],int b,int s);
void permu(int ar[],int x,int g);
void swap(int m,int n);
int main()
{
	int i,j,t,n,k=0;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		permu(arr,n,k);
		t--;
	}
	return 0;
}

void permu(int arr[],int n, int k)
{
	int i,check,m;
	if(k==n-1)
	{

	//	for(i=0;i<n;i++)
	//	printf("%d",arr[i]);

	}

		printf("\n");
	
	
		for(i=k;i<n;i++)
			
		{
			swap(k,i);
			permu(arr,n,k+1);
		        for(m=0;m<n;m++)
				printf("%d",arr[m]);
			printf("\n");
			sort(arr,k,n);
			swap(k,i);
	

		}
	
	
}

void swap(int a,int b)
{
	int t;
	t=arr[a];
	arr[a]=arr[b];
	arr[b]=t;
	return;
}

void sort(int arr[],int k,int n)
{
	int small,i,j;
	for(i=k;i<n;i++)
	{
		small=arr[i];
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<small)
				small=arr[j];
		}
		arr[j]=small;
	}
	return;
}





