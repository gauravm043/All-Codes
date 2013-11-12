#include<stdio.h>
int main()
{
	int i,k,j,t;
	char str[1000],w[1000],out[1000];
	char ch;
	scanf("%d",&t);
	while(t!=0)
	{
		char c;
		scanf("%[^ ]",w);
		c=getchar();
		scanf("%[^\n]",str);
		for(i=0;w[i]!='\0';i++)
		{
			ch=w[i];
			for(j=0;str[j]!='\0';j++)
			{
				k=j;
				if(str[j]==ch)
					{
						while((str[j]!='\0'))
						{
							str[j]=str[j+1];
							j++;
						}
						j=k-1;
					}
			}
		}
		t--;
	
	printf("%s\n",str);
	}
	return 0;
}





