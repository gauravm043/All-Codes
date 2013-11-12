#include<stdio.h>
#include<math.h>
#include<string.h>
int che=0;
char num[10]={0};
char con[10]={0};
int decimal(char n[],int base,int s);
void convert(int x,int base2);
int main()
{
	int i,t,l,b,m,c,nu,r;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d %d",&b,&c);
		m=getchar();
		scanf("%[^\n]",num);
                l=strlen(num);
		nu=decimal(num,b,l);
		convert(nu,c);
		con[che]='\0';
		printf("%s",con);
		printf("\n");
		che=0;
		t--;
	}
	return 0;
}

int decimal(char a[],int b,int le)
{
	int i,r,sum=0,t;
	for(i=0;i<=le-1;i++)
	{
		if(a[le-i-1]=='A')
		t=10*pow(b,i);
		else if(a[le-i-1]=='B')
			t=11*pow(b,i);
		else if(a[le-i-1]=='C')
			t=12*pow(b,i);
		else if(a[le-i-1]=='D')
			t=13*pow(b,i);
		else if(a[le-i-1]=='E')
			t=14*pow(b,i);
		else if(a[le-i-1]=='F')
			t=15*pow(b,i);
		else
		{
			r=(a[le-i-1]-'0');
			t=r*pow(b,i);
		}
		sum=sum+t;
	}
	return sum;
}
void convert (int nu,int b2)
{
	int r;
	char c;
	if(nu==0)
		return;
	convert(nu/b2,b2);
	r=nu%b2;
	if(r>=10&&r<=15)
	{
		con[che]=r+'7';
		che++;
	}
	else
	{
		con[che]=r+'0';
		che++;
	}

	return;
}










