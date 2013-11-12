#include<stdio.h>
int stack[500001];
int arr[500001];
int wf[500001];
int wb[500001];
void w_b();
void print(int arr[],int f);
int main()
{
     int t,i;
     int n,top;
     scanf("%d",&t);
     while(t--)
     {
	  for(i=0;i<500001;i++)
	  {
	       wf[i]=-1;
	       wb[i]=-1;
	  }

	  top=-1;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	       scanf("%d",&arr[i]);

	  /* MINIMUM INDEX */

	  for(i=0;i<n;i++)
	  {

	       if(top==-1)
	       {
		    top++;
		    stack[top]=i;
	       }
	       else if(arr[i]<=arr[stack[top]])
	       {
		    top++;
		    stack[top]=i;
	       }
	       else
	       {
		    while(top!=-1&&arr[i]>arr[stack[top]])
		    {
			 wf[stack[top]]=i;
			 stack[top]=i;
			 if(top!=0&&arr[i]>arr[stack[top-1]])
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
	       else if(arr[i]<=arr[stack[top]])
	       {
		    top++;
		    stack[top]=i;
	       }
	       else
	       {
		    while(top!=-1&&arr[i]>arr[stack[top]])
		    {
			 wb[stack[top]]=i;
			 stack[top]=i;
			 if(top!=0&&arr[i]>arr[stack[top-1]])
			 {
			      top--;
			 }
		    }
	       }





	  }



	  long long int sum=0;
	  int p;

	  printf("\n");

	  /* INDEX RESOLUTION */
	  for(i=0;i<n;i++)
	  {
	       printf("hello%d\n",i);
	       if(wf[i]!=-1)
	       {
		    wf[i]=wf[i]-i;
	       }
	       else
	       {
		    wf[i]=n-1-i;
	       }
	       if(wb[i]!=-1)
	       {
		    wb[i]=i-wb[i];
	       }
	       else
	       {
		    wb[i]=i;
	       }
	  }
	  for(i=0;i<n;i++)
	  {
	       p=i+wf[i];
	       if(wf[i]<=wb[p])
	       {
		    printf("wf-->%d\ni-->%d\n",wf[i],i);
		    sum=sum+wf[i];
		    printf("sum-->%lld",sum);
	       }
               else
	       {
		    printf("wf-->%d\ni-->%d\n",wf[i],i);

		    sum=sum+wf[i]-wb[p];
		    printf("sum-->%lld\n",sum);
	       }
	  }
	  
	  print(wb,n);
	  printf("\n");
	  print(wf,n);
	  printf("ans-->%lld\n",sum);
	  //printf("\n");

     }
     return 0;
}

void print(int x[],int n)
{
     int i;
     for(i=0;i<n;i++)
	  printf("%d ",x[i]);
}
