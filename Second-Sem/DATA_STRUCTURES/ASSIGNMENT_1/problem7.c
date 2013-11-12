#include<stdio.h>
#include<string.h>
char arr[1000000];
char palin[1000000];
int main()
{
     int t,mid,n,i,j,flag,ans,get;
     scanf("%d",&t);
     while(t!=0)
     {
	  flag=ans=get=0;
	  t--;
	  scanf("%s",arr);
	  strcpy(palin,arr);
	  n=strlen(arr);
	  if(n==1)
	  {
	       if(arr[0]!='9')
		    printf("%c\n",arr[0]+1);
	       else
		    printf("11\n");
	       continue;
	  }
	  mid=n/2;
	  for(i=0,j=n-1;i<mid;i++,j--)
	  {
	       palin[j]=arr[i];
	  }


	  // SOLVING

	  for(i=mid;i<n;i++)
	  {
	       if(palin[i]>arr[i])
	       {
		    ans=1;
		    printf("%s\n",palin);
		    break;
	       }
	       if(palin[i]<arr[i])
	       {
		    flag=1;
		    break;
	       }

	  }

	  if(flag==1||ans==0)
	  {
	       if(palin[mid]!='9')
	       {
		    palin[mid]=palin[mid]+1;
		    if(n%2==0)                                                     //HERE
			 palin[mid-1]=palin[mid];
		    printf("%s\n",palin);
	       }
	       else
	       {
		    palin[mid]='0';
		    if(n%2==0)                                                       //HERE
			 palin[mid-1]='0';
		    j=mid+1;
		    for(;j<n;j++)
		    {
			 if(palin[j]=='9')
			 {
			      palin[j]='0';
			      if(n%2!=0)
			      palin[2*mid-j]='0';
			      else
				   palin[2*mid-j-1]='0';

			 }
			 else
			 {
			      palin[j]=palin[j]+1;
			      if(n%2!=0)
			      palin[2*mid-j]=palin[j];
			      else
				   palin[2*mid-j-1]=palin[j];
			      get=1;
			      printf("%s\n",palin);
			      break;
			 }
		    }

		    if(get==0)
		    {
			 printf("1");
			 for(i=1;i<n;i++)
			      printf("0");
			 printf("1\n");
		    }

	       }
	  }
     }
     return 0;
}

	  

