#include<stdio.h>
int ione[1000000];
int itwo[1000000];
int ithree[1000000];
int tr[1000000];
int cnt=0;
void binary(int tmp[],int size)
{

     while(tmp[0]!=0)
     {
	  if((tmp[size-1])%2==0)
	  {
	       printf("0 ");
	       cnt++;
	  }
	  else
	  {
	       printf("1 ");
	       cnt++;
	       tmp[size-1]=tmp[size-1]-1;
	  }
	  size=divide(size,tmp);
     }
     
     printf("\n");
     
}


int divide(int n,int tmp[])
{
     int size=0;
     int i,num;
     int x,p=tmp[0];
     x=0;
     if(p==1)
     {
	  x=tmp[0];
     }
     for(i=0;i<n;i++)
     {
	  if(p==1)
	  {
	       num=10*x+tmp[i+1];
	  }
	  else
	       num=10*x+tmp[i];
	  tmp[size]=num/2;
	  size++;
	  if(p==1)
	  {
	       i=i+1;
	       p=0;
	  }
	  if((num)%2==0)
	       x=0;
	  else
	       x=1;
     }
     
	  return size;
}



void copy(int m[],int s)
{
     int i;
     for(i=0;i<s;i++)
	  tr[i]=m[i];   
}

int add(int a[],int b[],int n1,int n2)
{
     int i,j,size;
     int p=1,q,r,c=0;
     size=n1>n2?n1:n2;
     if(n1==n2)
     {
	  if((a[0]+b[0])>8)
	  size=n1+1;
     }


     for(i=n1-1,j=n2-1; ;i--,j--)
     {

	  if(i>=0&&j>=0)
	  {
	  r=c+a[i]+b[j];
	  ithree[size-p]=r%10;
	  c=r/10;
	  }
	  else if(i>=0)
	  {
	       r=c+a[i];
	       ithree[size-p]=r%10;
	       c=r/10;
	  }
	  else if(j>=0)
	  {
	       r=c+b[j];
	       ithree[size-p]=r%10;
	       c=r/10;
	  }
	  else
	  {
	       ithree[size-p]=c;
	       break;
	  }
	  p++;
     }
     return size;
}
void print(int x[],int s)
{
     int i;
     for(i=0;i<s;i++)
	  printf("%d ",x[i]);
     printf("\n");
}

int main()
{
     int n1,i,n2;
     int size1,size2,size3;
     char ch;
     for(i=0; ;i++)
     {
	  scanf("%c",&ch);
	  if(ch==' ')
	       break;
	  else
	  {
	       ione[i]=ch-'0';
	  }
     }
     size1=i;

     for(i=0; ;i++)
     {
	  scanf("%c",&ch);
	  if(ch=='\n')
	       break;
	  else
	  {
	       itwo[i]=ch-'0';
	  }
     }

     size2=i;

     int test,c;
     scanf("%d",&test);

     while(test--)
     {
	  c=getchar();
	  scanf("%c",&ch);
	  if(ch=='S')
          c=getchar();
	  switch(ch)
	  {
	       case 'S':
		    scanf("%c",&ch);
		    if(ch=='1')
		    {
			 copy(ione,size1);
			 binary(tr,size1);
			 printf("\nDIGITS-->%d\n",cnt);
			 cnt=0;
		    }
		    else if(ch=='2')
		    {
			 copy(itwo,size2);
			 binary(tr,size2);
			 printf("\nDIGITS-->%d\n",cnt);
			 cnt=0;
		    }
		    else if(ch=='3')
		    {
			 copy(ithree,size3);
			 binary(tr,size3);
			 printf("\nDIGITS-->%d\n",cnt);
			 cnt=0;
		    }
		    break;
	       case 'A':
		    size3=add(ione,itwo,size1,size2);
		    print(ithree,size3);
		    break;
	  }
     }
     return 0;
}
