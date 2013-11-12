#include<stdio.h>
#include<math.h>
int arr[500];
int l[10000]={0};
int count=0,m2=0,check[500000],ins=1;
void per(int lj[],int n,int f,int a[]);
void decimal(int hu[],int gg);
int main()
{
	int n,j=0,w,index,temp,small,q,fd,gh,ed,test,oo;
	scanf("%d",&test);
	while(test!=0)
	{
	
		count=0;
		gh=0,ins=1,m2=0,j=0;
		int inp[500]={0};
		int l[10000]={0};

		scanf("%d",&n);
		
		for(fd=0;fd<n;fd++)
		{
			check[fd]=0;
			arr[fd]=0;
			scanf("%d",&inp[fd]);
		}

		for(fd=0;fd<n;fd++)
		{
			if(inp[fd]!=-34)
			{
				arr[gh]=inp[fd];
				gh++;
			}
			for(ed=0;ed<n;ed++)
			{
				if(inp[fd]==inp[ed]&&fd!=ed)
					inp[ed]=-34;
			
			
			}
		}

		n=gh;


		for(w=0;w<n;w++)
		{
			index=w;
			small=arr[w];
			for(q=w+1;q<n;q++)
			{
				if(arr[q]<small)
					{
						index=q;
					small=arr[q];
					}
			}

			temp=arr[w];
			arr[w]=small;
			arr[index]=temp;
		}




		for(oo=0;oo<n;oo++)
			printf("<<%d>>",arr[oo]);
		printf("\n");
	
		per(l,n,j,arr);
		test--;
	}
	return 0;
}
void per(int l[],int n,int j,int arr[])
{
	int i,r,k,m,t,dd,ff,flag;
	for(i=0;i<n;i++)
	{
		if(l[i]==0)
		{
			flag=dd=0;
			decimal(l,n);
			for(t=0;t<n;t++)
			dd=dd+(l[t]*pow(2,t));
			for(ff=0;ff<count-1;ff++)
		        if(check[ff]==dd)
			flag=1;
			if(flag==0&&ins!=1)
			{
		
			for(m=0;m<n;m++)
			{
				if(l[m]==1)
				{
				printf("%d ",arr[m]);
				}
			}
			printf("\n");
			}
			ins++;
			l[i]=1;
			per(l,n,j+1,arr);
			l[i]=0;
		}
	}


	if(j==n)
	{
		if(m2==0)
		{
		for(ff=0;ff<n;ff++)
			if(l[ff]==1)
				printf("%d ",arr[ff]);
		printf("\n");
		}
		m2++;
		return;
	}
	return;
}


void decimal(int l[],int n)
{
	int i;
	int sum=0;
	for(i=0;i<n;i++)
	sum=sum+(l[i]*pow(2,i));
	check[count]=sum;
	count++;
	return;
}







