#include<stdio.h>
int main()
{
	int i,j;
	char cp[100000],m=5,out[100000]={0},flag=0;
	scanf("%[^EOF]",cp);
		
	for(i=0,j=0;cp[i]!='\0';i++)
	{

		
		
		if(cp[i]=='/'&&cp[i+1]=='*')
		{
			i=i+2;
			flag=1;
		}
		else if(cp[i]=='*'&&cp[i+1]=='/')
		{
			flag=0;
			m=0;
			if(!flag)
			i=i+3;
		}
		if(flag)
		{
			continue;
		}
		else
		{
			if(m==0&&cp[i]=='\n')
				i=i+1;

			out[j]=cp[i];
			j++;
		}
		m=1;


	}

	out[j]='\0';
        printf("%s",out);
	return 0;
}
