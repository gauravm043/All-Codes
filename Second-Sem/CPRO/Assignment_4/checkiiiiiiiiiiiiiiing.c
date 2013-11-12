#include<stdio.h>
#include<math.h>
int arr[5]={1,2,3,4,5};
int l[10]={0};
int count=0,m2=0,check[100];


void per(int lj[],int n,int f,int a[]);
void decimal(int hu[],int gg);
int main()
{
	int n,j=0;
	scanf("%d",&n);
	per(l,n,j,arr);
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
			
			if(flag==0)
			{
			for(m=0;m<n;m++)
			{
				if(l[m]==1)
				{
				printf("%d",arr[m]);
				}
			}
			printf("\n");
			}
			l[i]=1;
			per(l,n,j+1,arr);
			l[i]=0;
		}
	}


	if(j==n)
	{
	/*	flag=0,r=0;
		decimal(l,n);

		for(ff=0;ff<n;ff++)
			r=r+(l[ff]*pow(2,ff));

		
		for(ff=0;ff<count-1;ff++)
		if(check[ff]==r);
		flag=1;

		if(flag==0)
		{
		for(k=0;k<n;k++)
			if(l[k]==1)
			printf("%d********",arr[k]);
			
		printf("\n");
		}*/

		if(m2==0)
		{
		for(ff=0;ff<n;ff++)
			if(l[ff]==1)
				printf("%d",arr[ff]);
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
	//printf("<<>> %d >><<",check[count]);
	count++;
}







