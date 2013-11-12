#include<stdio.h>
#include<math.h>
int kk[2000][2000]={0,0};
int arr[2000];
long double hi[2000];
void sort(long double j[],int f);
long double decimal(int i,int g);
int main()
{
	int i,j,ch,n,check,go,m;
	int g,n2,num[20],ff;
	printf("NUMBER OF ELEMENTS=");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	int d=0;
	int f=0;


	ch=pow(2,n);
	check=ch-1;
	while(check!=0)
	{

			m=0;
			for(j=check;j!=0;j=j>>1)
			{
				if((j&1)==1)
				{
				        kk[d][f]=  arr[n-m-1];
					f++;
				}
				m++;
			}

			hi[d]=decimal(d,n);

			f=0;
			d++;
		check--;
	}

	sort(hi,d);

/*	for(i=0;i<d;i++)
	{
		printf("%Lf",hi[i]);
		printf("\n");
	}*/

	for(i=0;i<d;i++)
	{
		g=0,go=1;
		n2=hi[i];
		for(ff=0;ff<20;ff++)
			num[ff]=0;
			while(n2!=0)
			{
				num[g]=n2%10;
				n2=n2/10;
				g++;
			}

			for(ff=g-1;ff>=0;ff--)
			{
				if(num[ff]==0)
					go=0;
				if(go==1)
					printf("%d ",num[ff]);
			}
				
				printf("\n");
			

	}

	return 0;
}

long double decimal(int i,int n)
{
	int m;
	long double sum=0;
	for(m=0;m<n;m++)
		sum=sum+(kk[i][m]*pow(10,n-m-1));
	return sum;
}

void sort (long double hi[],int n)
{
    
	int i=0,j=0,k;
	long double  small=0,temp=0;
	int index;
	for(i=0;i<n;i++)
	{
		k=0;
		small=hi[i];
		for(j=i+1;j<n;j++)
		{
			if(hi[j]<small)
			{
				k=1;
				small=hi[j];
				index=j;
			}
		}
		if(k==1)
		{
		temp=hi[i];
		hi[i]=small;
		hi[index]=temp;
		}
	}

	return;
}









