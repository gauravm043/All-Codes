#include<stdio.h>

float arr[100001];

float calculate(int s,int e,int n)
{
     int i;
     float min=arr[s];
     float max,time=0;

     for(i=s;i<=e;i++)
     {
	  if(arr[i]<min)
	       min=arr[i];
     }
     time+=min;
     max=0;
     for(i=0;i<s;i++)
     {
	  if(arr[i]>max)
	       max=arr[i];
     }
     for(i=e+1;i<=n;i++)
     {
	  if(arr[i]>max)
	       max=arr[i];
     }
     float temp=0;

     for(i=s;i<=e;i++)
     {
	  arr[i]=arr[i]*(float)(1-min/arr[i]);
	  if(arr[i]>0)
	  {
	       if(arr[i]>temp)
	       {
		    temp=arr[i];
	       }
	  }

     }
     temp=temp/2;
     max=max>temp?max:temp;
     time+=max;
     
     return time;
    
}



int main()
{
     int t,q;
     int n,i=0;
     int start,end,size;
     float time;

     scanf("%d",&n);
     size=n;
     while(n--)
     {
	  scanf("%f",&arr[i++]);
     }
     scanf("%d",&q);
     while(q--)
     {
	  scanf("%d%d",&start,&end);
	  time=calculate(start,end,size);
	  printf("%0.1f\n",time);
     }
     return 0;
}
