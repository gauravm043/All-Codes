#include<stdio.h>
int qs(int ar[],int a,int b,int h,int y);
int k,ans,mega=0;
int arr[10000000];
int N;
int main()
{
     int t,n,i,sum=0,flag=1;//flag1=0;
     scanf("%d",&t);
     while(t!=0)
     {
	  flag=1;
	  sum=sum+11;
	  ans=0;
	  mega=0;
	  scanf("%d",&n);
	  N=n;
	  t--;
	  for(i=0;i<n;i++)
	       scanf("%d",&arr[i]);
	  scanf("%d",&k);
	  ans=qs(arr,0,n,k-1,flag);
     }
     return 0;
}
int qs(int arr[],int i,int n,int k,int flag)
{
  
     if(ans!=0)
	  return mega;
     int pivot;
     pivot=arr[n-1];
     int l=i,u=i,t;
     for(u=i;u<n-1;u++)
     {
	  if(arr[u]<=pivot)
	  {
	       t=arr[l];
	       arr[l]=arr[u];
	       arr[u]=t;
	       l++;
	  }
     }
     t=arr[l];
     arr[l]=arr[n-1];
     arr[n-1]=t;

     if(l==k)
     {
	  printf("%d\n",arr[l]);
	  ans=1;
	  mega=arr[l];
	  return mega;
     }
     if(l<k)
	  qs(arr,l+1,n,k,flag);
     if(l>k)
	  qs(arr,i,l,k,flag);

}
