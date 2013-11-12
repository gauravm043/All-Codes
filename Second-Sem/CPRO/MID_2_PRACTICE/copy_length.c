#include<stdio.h>
//#include<string.h>
int strl(char st[]);
void stc(char to[],char from[]);
int main()
{
	int i,le,j;
	char string[100],cop[100];
	scanf("%[^\n]",string);
	printf("%s\n",string);
	//i=strlen(string);
	stc(cop,string);
	printf("%s\n",cop);
	le=strl(string);
	printf("LENGTH IS=%d\n",le);
	return 0;
}


int strl(char st[])
{
	int i=0,l=0;
	while(st[i]!='\0')
	{
		++l;
		i++;
	}
	return l;
}

void stc(char to[],char from[])
{
	int i=0;
	while(from[i]!='\0')
	{
		to[i]=from[i];
		++i;
	}
	to[i]='\0';
	return ;
}





