#include<stdio.h>
int main()
{
     int numbers[51];
     int test,i,j;
     int n,ch;
     scanf("%d",&test);
     while(test--)
     {
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	       scanf("%d",&numbers[i]);
	  for(i=1000;i>=1;i--)
	  {
	       ch=0;
	       for(j=0;j<n;j++)
	       {
		    if(numbers[j]%i!=0)
		    {
			 ch=1;
			 break;
		    }
	       }
	       if(ch==0)
		    break;
	  }
	  for(j=0;j<n;j++)
	       printf("%d ",numbers[j]/i);
	  printf("\n");
     }
     return 0;
}
