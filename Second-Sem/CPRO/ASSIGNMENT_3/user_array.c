#include<stdio.h>
int main()
{
	int flag=0,c;
		
	
	
	
	
	
	
	while((c=getchar())!=EOF)
		{
			if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))
			{
				if(flag==0)
					{
						flag=1;
						putchar('"');
						putchar(c);
					}
				else{putchar(c);}
			}
			else{
				if(flag==1)
				{
					flag=0;
					putchar('"');
					putchar(c);
				}

				else putchar(c);
			}
		}
	return 0;
}




			

				


