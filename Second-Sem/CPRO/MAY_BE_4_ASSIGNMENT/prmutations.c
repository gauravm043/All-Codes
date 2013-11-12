#include<stdio.h>
int arr[10]={0},n,counter=1;
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
	int i,temp;

	
	temp=arr[a];
	arr[a]=arr[b];
	arr[b]=temp;
	
	for(i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");

	counter++;
if(counter==18)
	swap(0,2);
	if(counter==24)
		return;
	if(counter%2==0&&counter%6!=0)
	{
		swap(a-1,b);
	}
	else if(counter%6==0)		
	{
		swap(0,b);
		counter++;
	}
	else
		swap(n-2,n-1);


}






