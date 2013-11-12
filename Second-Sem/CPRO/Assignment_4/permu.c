#include<stdio.h>
int arr[100];
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
	int i;
	if(k==n-1)
	{
		
                        
		        for(i=0;i<n;i++)
			printf("%d  ",arr[i]);
		printf("\n");
	}
	
		for(i=k;i<n;i++)
			
		{
			swap(k,i);
			permu(arr,n,k+1);
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




