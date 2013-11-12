#include<stdio.h>
char cp[1000000],out[1000000],m=1,flag=0;
int main()
{
	int i=0,j=0;
	scanf("%[^EOF]",cp);
		
	for(i=0,j=0;cp[i]!='\0';i++)
	{
		if(cp[i]=='('&&cp[i+1]=='"')
			m=0;
		else if(cp[i]==')'&&cp[i+1]==';')
			m=1;

		
		
		if(cp[i]=='/'&&cp[i+1]=='*')
		{
			if(m==1)
			i=i+2;
			flag=flag+1;
		
		}
		
		else if(cp[i]=='*'&&cp[i+1]=='/')
		{
			flag=flag-1;
			
			if(flag==0&&m==1)
				i=i+2;

		}
		if(flag!=0&&m==1)
		{
			continue;
		}
		else
		{
			out[j]=cp[i];
			j++;
		}


	}

	out[j]='\0';
        printf("%s",out);
	return 0;
}
