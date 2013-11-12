#include<stdio.h>
int main()
{
	char c,t,ec,x=0,i;
	int f=1;
	int a1[1000];
	while((c=getchar())!=EOF)
	{
		ec=c;
	   t=((c>='0'&&c<='9')||(c>='A'&&c<='Z')||(c>='a'&&c<='z'));
		if(t)
		{
		        if(f==1)
			{


			a1[x]='"';
			x++;
			a1[x]=c;
			f=0;
			}else
				a1[x]=c;
		}
		else
		{
			if(f==0)
			{
			   a1[x]='"';
			   f=1;
			   x++;
			   a1[x]=c;
			}
			else
			   a1[x]=c;
		}

		x++;
	}
		   if((ec>='0'&&ec<='9')||(ec>='A'&&ec<='Z')||(ec>='a'&&ec<='z'))
            a1FIL[x]='"';
	for(i=0;i<=x;i++)
	 printf("%c",a1[i]);
	printf("\n");
	return 0;
}
