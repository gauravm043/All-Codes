#include<stdio.h>
int main()
{
	int t,i,src,lin,ch=0,f,l,m,mid=0,c=0,temp,n,min,j;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&n);
		int arr[n];
		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);
		scanf("%d",&src);
		for(i=0;i<n;i++)
		{
			min=i;
			for(j=i+1;j<n;j++)
			{
				if(arr[j]<arr[min])
				min=j;
			}
			temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
			printf("%d ",arr[i]);
		}

		for(i=0;i<n;i++)
			if(arr[i]==src)
			{ch=1;lin=i;}

		i=1;
		f=0,l=n-1,m=(f+l)/2;
		if(ch==1)
		{
		while(c!=0)
		{
			if(arr[m]==src)
			{
				i++;
				c=1;
			        break;
			}

			else if(arr[m]<src)
			{
				f=m;
				m=(f+l)/2;
				i++;
			}

			else if(arr[m]>src)
			{
				i++;
				l=m;
				m=(f+l)/2;
			}
		
		}
		

        
		
			printf("\n\nNUMBER FOUND");
			printf("%d %d",lin+1,i+1);


		
		}


		if(ch!=1)
			printf("\nNUMBER NOT FOUND");

	t--;
	}
	return 0;
}




				

