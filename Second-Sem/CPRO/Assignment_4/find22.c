#include<stdio.h>
#include<string.h>
int main()
{
	int t,f=0,m=0,l,h,check,c,i,j=0,flag=0,k;
	char w[1000]={0},wc[1000]={'\0'},str[100000];
	scanf("%d",&t);
	while(t!=0)
	{
		check=0,f=0,flag=0,m=0,j=0;
		scanf("%s",w);
		l=strlen(w);
		c=getchar();
		scanf("%[^\n]",str);
		for(i=0;str[i]!='\0';i++)
		{
			
			if(str[i]==' '||str[i]=='\t'||str[i]=='\n')
			{
				if(f==1)
					wc[j]='\0';
				j=0;
				flag=0;
			}

			else
			{
				f=1;
				flag=1;
				wc[j]=str[i];
				j++;
			}

			if(str[i+1]=='\0')
				flag=0;
			if(flag==0)
			{
				check=0;
				m=0;
				//printf("%s",wc);

				//printf("%d",strcmp(w,wc));
				if(!strcmp(w,wc))
				{
					m=5;
					printf("FOUND\n");
					break;
				}


				for(l=0;l<1000;l++)
					wc[l]='\0';
				
			}
			if(m==5)
				break;

		}

		if(m!=5)
		printf("NOT FOUND\n");
		t--;
	}
	return 0;
}

					





