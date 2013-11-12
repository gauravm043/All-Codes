#include<stdio.h>
long long int stack[100001];
long long int arr[100001];
long long int wb[100001];
long long int wf[100001];
void print(long long int arr[],int f);
int main()
{
     int t,i;
     int n,top;
     while(1)
     {
	  for(i=0;i<10001;i++)
	  {
	       wf[i]=-1;
	       wb[i]=-1;
	  }

	  top=-1;
	  scanf("%d",&n);
	  if(n==0)
	       return 0;
	  for(i=0;i<n;i++)
	       scanf("%lld",&arr[i]);

	  /* MINIMUM INDEX */
	  for(i=0;i<n;i++)
	  {

	       if(top==-1)
	       {
		    top++;
		    stack[top]=i;
	       }
	       else if(arr[i]>=arr[stack[top]])
	       {
		    top++;
		    stack[top]=i;
	       }
	       else
	       {
		    while(top>=0&&arr[i]<arr[stack[top]])
		    {
			 wf[stack[top]]=i;
			 stack[top]=i;
			 if(top>=1&&arr[i]<arr[stack[top-1]])
			 {
			      top--;
			 }


		    }
	       }

	  }
	

  
     top=-1;

     for(i=n-1;i>=0;i--)
     {

	  if(top==-1)
	  {
	       top++;
	       stack[top]=i;
	  }
	  else if(arr[i]>=arr[stack[top]])
	  {
	       top++;
	       stack[top]=i;
	  }
	  else
	  {
	       while(top>=0&&arr[i]<arr[stack[top]])
	       {
		    wb[stack[top]]=i;
		    stack[top]=i;
		    if(top>=1&&arr[i]<arr[stack[top-1]])
		    {
			 top--;
		    }


	       }
	  }

     }
   

     long long int  area=0;
     long long int  sum=0;

     /* WIDTH ARRAY */

//     print(wf,n);
  //   print(wb,n);

     for(i=0;i<n;i++)
     {
	  if(wb[i]!=-1)
	       wb[i]=i-wb[i];
	  else
	       wb[i]=i+1;
	  if(wf[i]!=-1)
	  {
	       wf[i]=wf[i]-i;
	  }
	  else
	  {
	       wf[i]=n-i;
	  }
    
	 wf[i]=wf[i]+wb[i]-1;
	 sum=wf[i]*arr[i];

	//      printf("W-->%lldH-->%lldAREA-->%lld\n",wf[i],arr[i],wf[i]*arr[i]);

	 if(sum>area)
	 {
	      area=sum;
	 }

     }
 //    print(wf,n);
     //print(wb,n);
   printf("%lld\n",area);
     }

   return 0;
}
void print(long long int x[],int n)
{
     int i;
     for(i=0;i<n;i++)
	  printf("%lld  ",x[i]);
     printf("\n");
}
