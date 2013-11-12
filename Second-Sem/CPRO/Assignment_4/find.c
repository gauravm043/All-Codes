#include<stdio.h>
#include<string.h>
int main()
{
	int t,m,l,h,check,c,i,j=0,flag=0,k;
	char w[1000]={0},wc[1000]={0},str[100000];
	scanf("%d",&t);
	while(t!=0)
	{
		check=0;
		scanf("%[^ ]",w);
		c=getchar();
		scanf("%[^\n]",str);
		for(i=0;str[i]!='\0';i++)
		{
			
			if(str[i]==' '||str[i]=='\t'||str[i]=='\n')
			{
				j=0;
				flag=0;
			}

			else
			{
				flag=1;
				wc[j]=str[i];
				j++;
			}
			if(flag==0)
			{
				printf("%s",wc);
				/*for(h=0;w[h]!='\0';h++)
				{
					if(w[h]==wc[h])
					check++;
					if(check==h-1)
					{
						m=5;
						printf("FOUND\n");
						break;
					}
				}
				check=0;
				if(m==5)
					break;*/

				for(l=0;l<1000;l++)
					wc[l]=0;
				//printf("%d",k);
				
			}

		}

		if(m!=5)
		printf("NOT FOUND\n");
		t--;
	}
	return 0;
}

					





