#include<stdio.h>
char str[201];
int main()
{
     int t,cost,c,i;
     char ch='a';
     scanf("%d",&t);
     while(t--)
     {
	  i=0;
	  int arr[125]={0};
	  scanf("%s",str);
	  ch='a';
	  cost=0;
	  while(str[i]!='\0')
	  {
	       ch=str[i];
	       if(arr[ch]==0)
	       {

		    arr[ch]=1;
		    cost++;

	       }
	       else
		    arr[ch]=0;
	       i++;
	  }

	  printf("%d\n",cost);
     }

     return 0;
}
