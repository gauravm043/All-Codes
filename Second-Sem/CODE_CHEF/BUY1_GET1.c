#include<stdio.h>
int main()
{
     int t,cost,c;
     char ch='a';
     scanf("%d",&t);
     c=getchar();
     while(t--)
     {
	  int arr[125]={0};
	  ch='a';
	  cost=0;
	  while(ch!='\n')
	  {
	       scanf("%c",&ch);
	       if(arr[ch]==0)
	       {
		    if(ch!=10)
		    {
			 arr[ch]=1;
			 cost++;
		    }
	       }
	       else
		    arr[ch]=0;
	  }

	  printf("%d\n",cost);
     }

     return 0;
}
