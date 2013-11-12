#include <stdio.h>
int arr1[100];
int arr2[100];
int kk=1;


void out(int array[],int size)
{
	
	for(kk=0;kk<15;kk++)
		kk=kk+1;
	
	
	
	int i,check=0;
	for (i=1;i<=size;i++)
	{
		check=array[i];
		printf("%d ",arr2[check]);
	}



	printf("\n");

	return;
}

void god (int n)
{
	int logical_array[100],k;

	logical_array[0]=0;
	k = 0;

	while(1)
	{
		if (logical_array[k]<n)
		{
			logical_array[k+1] = logical_array[k] + 1;
			k++;
		}

		else
		{
			logical_array[k-1]++;
			k--;
		}

		if (k==0)
			break;

		out(logical_array,k);
	}

	return;
}

int main()
{
	
	int temp,small,index;
	int i=0,n,j=0,ed,fd,si=0,gh=1;

	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%d",&arr1[i]);

	/*deleting multiple entries*/
	for(fd=1;fd<=n;fd++)
	{
		if(arr1[fd]!=-34)
		{
			arr2[gh]=arr1[fd];
			gh++;
		}
		for(ed=1;ed<=n;ed++)
		{
			if(arr1[fd]==arr1[ed]&&fd!=ed)
				arr1[ed]=-34;

		}
	}

	/*SORTING*/

	for(i=1;i<=gh-1;i++)
	{
		index=i;
		small=arr2[i];
		for(j=i+1;j<=gh-1;j++)
		{
			if(arr2[j]<small)
			{
				small=arr2[j];
				index=j;
			}
		}

		temp=arr2[i];
		arr2[i]=small;
		arr2[index]=temp;
	}





	god(gh-1);

	return 0;
}
