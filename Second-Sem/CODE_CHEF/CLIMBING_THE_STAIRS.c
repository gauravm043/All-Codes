 #include<stdio.h>
int arr[1000001];
int main()
{
     int i;
     arr[0]=1;
     arr[1]=1;
     for(i=2;i<1000001;i++)
     {
	  arr[i]=((arr[i-1])%1000000007+(arr[i-2])%1000000007)%1000000007;
     }
    
     int t,cnt,M,G;
     int num;
     scanf("%d",&t);
     while(t--)
     {
	  cnt=0;
	  scanf("%d",&num);
	  scanf("%d",&G);
	  M=arr[num];
	  printf("M:%d",M);
	  M=M%1000000007;
	  while(M!=0)
	  {
	       cnt+=M&1;
	       M=M/2;
	  }
	  if(cnt==G)
	       printf("CORRECT\n");
	  else
	       printf("INCORRECT\n");

     } 
     return 0;
}
