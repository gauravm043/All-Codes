#include<stdio.h>
int main()
{
	int i,j;
	char cp[1000],out[1000]={0},k=0,a[1]={"!"},flag=1;
	scanf("%[^EOF]",cp);
		
	for(i=0,j=0;cp[i]!='\0';i++)
	{
	
		if(flag==1&&cp[i]=='('&&cp[i+1]=='"')
		{
			k=1;
		}
		else if(k==1&&cp[i]==')'&&cp[i+1]==';')
		{
			k=0;
		}
		
		if(cp[i]=='/'&&cp[i+1]=='*'&&flag==1&&k==0)
		{
	
			flag=0;
			++i;
			continue;
		}
		else if(cp[i]=='*'&&cp[i+1]=='/'&&flag==0&&k==0)
		{
			//cp[i+2]=a[0];
			flag=1;
			++i;
			continue;
		}
                else if(flag==1)
		{
			out[j]=cp[i];
			j++;
		}
		if(cp[i]=='\0'&&flag==1)
		{
			out[j]=='\0';
		}

	}
        printf("%s",out);
	return 0;
}
