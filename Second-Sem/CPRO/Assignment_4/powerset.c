#include<stdio.h>
int temp[20];
void sort(int n,int a[]);
void per(int a[20],int  start,int n,int size)
{
	int i,j,c;
	for(i=start;i<n-1;i++)
	{
		temp[size-1]=a[i];
		for(j=0;j<size;j++)
			printf("%d ",temp[j]);
		printf("\n");	
		per(a,i+1,n,size+1);


	}

}
int main()
{
	int a[20],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	
	sort(n,a);
	per(a,0,n+1,1);

	return 0;

}

void sort(int n,int a[])
{

	int i,j,k,min,temp;

	for(i=0;i<n;i++)

	{

		min=a[i];

		for(j=i;j<n;j++)

		{

			if(a[j]<min)

			{

				min=a[j];

				k=j;

			}

		}

		if(min!=a[i])

		{

			temp=a[i];

			a[i]=min;

			a[k]=temp;

		}

	}

}

