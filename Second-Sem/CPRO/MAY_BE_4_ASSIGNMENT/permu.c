#include<stdio.h>
int arr[10]={0},n,counter=1,check=1;
void swap(int a,int b);
int main()
{
	static m=1;
	int i;
	
	printf("ENTER VALUE OF N=\n");
	scanf("%d",&n);

	printf("ENTER VALUES=\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	if(m==1)
	{
		swap(n-2,n-1);
		m++;
	}

	return 0;
}

void swap(int a,int b)
{
	int i,r,temp;
        
	r=a;
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	counter++;

	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");

	if(a==0)
		return;
	else
	{
		if(c==fact(x))
		swap(a-1,b);
	}
}


	









