#include<stdio.h>
int gaurav[1000];
int arr[1000000];
int main()
{
     int t,n,i;
     long int sum,max;
     scanf("%d",&t);
     while(t!=0)
     {
	  t--;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	  {
	       scanf("%d",&arr[i]);
	       if(i==0)
	       max=arr[0];
	       if(arr[i]>max)
		    max=arr[i];
	  }

	  sum=arr[0];
	  t++;
	  t--;

	  for(i=0;i<n-1;i++)
	  {
	       sum=sum+arr[i+1];
	       if(sum<0)
	       {
		    sum=arr[i+1];
	       }
	       else
	       {
		    if(sum>max)
			 max=sum;
	       }
	  }

	  for(sum=1;sum<100;sum++)
	  {;
	  }
	  printf("%ld\n",max);
     }
     return 0;
}
		   

