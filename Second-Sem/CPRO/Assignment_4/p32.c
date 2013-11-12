#include<stdio.h>
int main()
{
	int A[1000],input[1000],a[1000],i,n,j,temp,k,m,s,x,y,o,mul,print,last,q,flag;
	scanf("%d",&n);
	k=0;
	for(i=0;i<n;i++)
        {
                 flag=0;
                 scanf("%d",&q);
                 for(j=0;j<i;j++)
                 {
                        if(q==a[j])
                        {flag=1;break;}
                 }
                 if(flag==0)
                a[k++]=q;
         }n=k;
/*	 for(i=0;i<n;i++)
	 printf("%d ",a[i]);*/
	for(i=0;i<n;i++)
		A[i]=a[n-i-1];
	for(i=0;i<n;i++)
		for(j=n-1;j>=i;j--)
			if(A[j]<A[j-1])
			{
				temp=A[j];
				A[j]=A[j-1];
				A[j-1]=temp;
			}
	/*	for(i=0;i<n;i++)
			printf("%d ",A[i]);*/
	for(i=0;i<n;i++)
		input[i]=A[i];

	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
			printf("%d ",A[j]);
		printf("\n");
	}
	print=last=k=n-1;mul=1;
	for(m=1;m<=n;m++)
		mul*=2;
	for(s=0;s<mul-n-1;s++)
	{
		if(A[k]==input[last])
		{
			print--;
			k--;
			for(y=0;y<n;y++)
                        {
	                        if(A[k]==input[y])
                                      break;
                        }
			A[k]=input[y+1];
		}
		else
		{
			print++;
			for(x=0;x<n;x++)
			{
				if(A[k]==input[x])
					break;
			}
			A[++k]=input[x+1];
		}
		for(o=0;o<=print;o++)
			printf("%d ",A[o]);
		k=print;
		printf("\n");
	}
	return 0;
}
