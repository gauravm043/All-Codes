#include<stdio.h>
#include<string.h>
int main()
{
	int T;
	scanf("%d",&T);
	while(T>0)
	{
	T--;
		char a[1000000];
	scanf("%s",a);
	int n;
	n=strlen(a);
	if(n==1 && a[0]!=57)
		printf("%d\n",a[0]-47);
	else if(n==2)
	{
		if(a[0]==49 && a[1]==48)
			printf("11\n");
		else if(a[0]==57)
		{
			if(a[1]==57)
			printf("101\n");
			else
				printf("99\n");
		}
		else if(a[0]<=a[1])
		{
		a[0]=a[0]+1;
		a[1]=a[0];
		printf("%d%d\n",a[0]-48,a[1]-48);
		}
		else if(a[0]>a[1])
		{
			a[1]=a[0];
			printf("%d%d\n",a[0]-48,a[1]-48);
		}
	}
	else
	{
	int m;
	if(n%2==0)
		m=n/2-1;
	else
		m=n/2;
	int flag1=1;
	int flag2=1;
	int flag3=1;
	int i;
	for(i=m;i>=0;i--)
	{
		int j=m;
		while(flag1>0 && j>=0)
		{
			if(a[j]<a[(n-1)-j])
			{
				flag1=0;
				break;
			}
			j--;
		}
/*		if(m==(n-1)-m)
		{
		if(a[m-1]<a[m+1])
			flag1=0;
		}
		else
		{
			if(a[m]<a[(n-1)-m])
				flag1=0;
		} */
		if(a[i]!='9' || a[(n-1)-i]!='9' || a[n/2]!='9')
			flag2=0;
		if(a[i]!=a[(n-1)-i])
			flag3=0;
	}
	if(flag2==1)
	{
		printf("1");
		for(i=0;i<(n-1);i++)
		printf("0");
		printf("1\n");
	}
	else if(flag1==0 || flag3==1)
	{
		int car=1;
		int sum=0;
		i=m;
		while(car!=0)
		{
			sum=a[i]-48+car;
			a[i]=(sum%10)+48;
			car=sum/10;
			i--;
		}
		for(i=m;i>=0;i--)
		a[(n-1)-i]=a[i];
	}
	else if(flag1==1)
	{
		for(i=m;i>=0;i--)
		a[(n-1)-i]=a[i];
	}
	if(flag2==0)
	{
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]-48);
	}
	printf("\n");
	}
	}
	}
	return 0;
}


