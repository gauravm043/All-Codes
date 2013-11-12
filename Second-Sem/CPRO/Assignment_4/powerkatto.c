#include<stdio.h>
#include<math.h>
int arr[30];
int l[30]={0};
int check[500000][30];

int count=0,m2=0,ins=1;
void per(int lj[],int n,int f,int a[]);
int main()
{
	int n,j=0,w,index,temp,small,q,fd,gh,ed,test,oo;
	count=0;
	gh=0,ins=1,m2=0,j=0;
		int inp[500]={0};
		scanf("%d",&n);
		
		for(fd=0;fd<n;fd++)
		{
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




		//for(oo=0;oo<n;oo++)
		//	printf("<<%d>>",arr[oo]);
/*CHECK	*/
		per(l,n,j,arr);
	
	return 0;
}
void per(int l[],int n,int j,int arr[])
{
	int i,r,k,m,t,dd,ff,flag,mm,uu=0;
	for(i=0;i<n;i++)
	{
		
			flag=dd=0;
				
		if(l[i]==0)
		{
			for(mm=0;mm<n;mm++)
			{
				check[count][mm]=l[mm];
			}

			count++;

			//search

		       for(dd=0;dd<count-1;dd++)
			{
				for(mm=0;mm<n;mm++)
				{
					if(check[dd][mm]==l[mm])
					{
						uu++;
					}
				}

					if(uu==n)
					{
						flag=1;
						break;
					}
					else
					{
						uu=0;
					}
			}

                        if(flag==0)
			{

			for(m=0;m<n;m++)
			{
				if(l[m]==1)
				{
				printf("%d ",arr[m]);
				}
			}
			if(count>1)
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








