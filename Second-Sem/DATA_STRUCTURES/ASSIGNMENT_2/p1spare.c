#include<stdio.h>
int ione[1000000];
int itwo[1000000];
int ithree[1000000];
int tr[1000000];
int tr2[1000000];
int cnt=0;
int ADD(int a[],int b[],int h,int f);
int multiply(int a[],int b[],int y,int u);
void binary(int tmp[],int size)
{

     while(tmp[0]!=0)
     {
	  cnt++;
	  if((tmp[size-1])%2!=0)
	  {
	       tmp[size-1]=tmp[size-1]-1;
	  }
	  size=divide(size,tmp);
     }

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

void COP(int x[],int n)
{
     int i,tmp;
     for(i=0;i<n/2;i++)
     {
	  tmp=x[i];
	  x[i]=x[n-i-1];
	  x[n-i-1]=tmp;
     }
}


int add(int a[],int b[],int n1,int n2)
{
     int i,j,size=0;
     int q,r,c=0;
     int check;


     for(i=n1-1,j=n2-1; ;i--,j--)
     {

	  if(i>=0&&j>=0)
	  {
	       r=c+a[i]+b[j];
	       ithree[size]=r%10;
	       c=r/10;
	  }
	  else if(i>=0)
	  {
	       r=c+a[i];
	       ithree[size]=r%10;
	       c=r/10;
	  }
	  else if(j>=0)
	  {
	       r=c+b[j];
	       ithree[size]=r%10;
	       c=r/10;
	  }
	  else
	  {
	       ithree[size]=c;
	       break;
	  }
	  size++;
     }
     if(c!=0)
     {
	  ithree[size]=c;
	  size++;
     }

     return size;
}
void print(int x[],int s)
{
     int i;
     for(i=0;i<s;i++)
	  printf("%d",x[i]);
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
	       case 'P':

		    print(ithree,size3);
		    break;
	       case 'S':
		    scanf("%c",&ch);
		    if(ch=='1')
		    {
			 copy(ione,size1);
			 binary(tr,size1);
			 printf("%d\n",cnt);
			 cnt=0;
		    }
		    else if(ch=='2')
		    {
			 copy(itwo,size2);
			 binary(tr,size2);
			 printf("%d\n",cnt);
			 cnt=0;
		    }
		    else if(ch=='3')
		    {
			 copy(ithree,size3);
			 binary(tr,size3);
			 printf("%d\n",cnt);
			 cnt=0;
		    }
		    break;
	       case 'A':
		    size3=add(ione,itwo,size1,size2);
		    COP(ithree,size3);
		    break;

		    /* DEALING SEPARATELY */

	       case 'M':
		    size3=multiply(ione,itwo,size1,size2);
		    break;

	  }
     }
     return 0;
}




int multiply(int a[],int b[],int n1,int n2)
{
     int i,j;
     int s1=0,c1=0;
     int s2=1,c2=0;
     tr2[0]=0;
     for(j=n1-1;j>=0;j--)
     {
	  tr[s1]=(c1+b[n2-1]*a[j])%10;
	  c1=(c1+b[n2-1]*a[j])/10;
	  tr2[s2]=(c2+b[n2-2]*a[j])%10;
	  c2=(c2+b[n2-2]*a[j])/10;
	  printf("carry==%d\n",c2);
	  s1++;
	  s2++;
     }
     if(c1!=0)
     {
	  tr[s1]=c1;
	  s1++;
     }
     if(c2!=0)
     {
	  tr2[s2]=c2;
	  s2++;
     }


     print(tr,s1);
     printf("\n");
     print(tr2,s2);
     s1=ADD(tr,tr2,s1,s2);
     print(tr,s1);
     int p1=1;
     int m;

     for(i=n2-3;i>=0;i--)
     {
	  p1++;
	  c2=0;
	  s2=p1+1;
	  for(j=n1-1;j>=0;j--)
	  {

	      
	    
	       for(m=0;m<=p1;m++)
	       {
		    tr2[m]=0;
	       }



	       tr2[s2]=(c2+a[j]*b[i])%10;
	       c2=(c2+a[j]*b[i])/10;
	       s2++;
	  }
	  if(c2!=0)
	  {
	       tr2[s2]=c2;
	       s2++;
	  }

	  s1=ADD(tr,tr2,s1,s2);
	  printf("tr2-->>");
	  print(tr2,s2);
	  printf("tr-->>");
	  print(tr,s1);


     }


     int f=0;
     for(i=s1-1;i>=0;i--)
     {
	  if(tr[i]!=0&&f==0)
	       f=1;
	  if(f==1)
	       ithree[s1-1-i]=tr[i];
     }
     return s1;
}









int ADD(int a[],int b[],int n1,int n2)
{
     int i,j,size=0;
     int q,r,c=0,check;
     check=n1>n2?n1:n2;

     for(i=0,j=0;i<check&&j<check ;i++,j++)
     {

	  if(i>=0&&j>=0)
	  {
	       r=c+a[i]+b[j];
	       tr[size]=r%10;
	       c=r/10;
	  }
	  else if(i>=0)
	  {
	       r=c+a[i];
	       tr[size]=r%10;
	       c=r/10;
	  }
	  else if(j>=0)
	  {
	       r=c+b[j];
	       tr[size]=r%10;
	       c=r/10;
	  }
	  else
	  {
	       tr[size]=c;
	       break;
	  }
	  size++;
     }
     if(c!=0)
     {
	  tr[size]=c;
	  size++;
     }

     return size;
}
