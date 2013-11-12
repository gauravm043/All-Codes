#include<stdio.h>
int main()
{
	long long int t,i,arr[2010],src,q,c,index,f,l,m,temp,n,min,j;
	scanf("%lld",&t);
	while(t!=0)
	{
		scanf("%lld",&n);
		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);
		
		scanf("%lld",&q);

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
		}

		
		while(q!=0)
		{
			scanf("%lld",&src);

		
		/*f=0,l=n-1,m=(f+l)/2,c=0;
		
		while(c!=1)
		{

			if(f<l)
			{

			if(arr[m]==src)
			{
				index=m;
				c=1;
			        break;
			}


			else if(arr[m]<src)
			{
				f=m;
				m=(f+l)/2;
			}

			else if(arr[m]>src)
			{
				l=m;
				m=(f+l)/2;
			}
			}
			else
			{

				printf("-1");
				printf("\n");
				break;
			}
		
		}*/
                 
			for(i=0;i<n;i++)
			{
				if(arr[i]==src)
				{index=i;
				c=1;}
			}

		
			if(c==1)
		{
			printf("%lld\n",index);
		}
			else
				printf("-1\n");

		q--;
		}
		t--;
	}
	return 0;
}

		

        

				

