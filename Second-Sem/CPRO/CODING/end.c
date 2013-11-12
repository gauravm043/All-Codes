#include<stdio.h>
int prime[10000000],moves,grid[360][360],prime_ch[10000000];
void crack_even(int a,int b,int c);
void crack_odd(int a,int b,int c);
int main()
{
     int i,j,k=2;
     /*SIEVE*/
     for(i=0;i<10000000;i++)
     {
	  if(i%2!=0)
	       prime[i]=i;
	  else
	       prime[i]=-1;
     }
     prime[2]=2;
     prime[0]=prime[1]=-1;
     for(i=3;i<10000000;i++)
     {
	  if(prime[i]!=-1)
	  {
	       prime_ch[i]=k;
	       k++;
	       for(j=2*i;j<10000000;j=j+i)
		    prime[j]=-1;
	  }
     }
     /*SIEVE*/
     prime_ch[2]=1;


     int n,t;
     scanf("%d",&t);
     while(t--)
     {
	  moves=0;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	       for(j=0;j<n;j++)
	         scanf("%d",&grid[i][j]);

	  /*FINDING MOVES*/

	  for(i=0;i<n;i++)
	  {
	       for(j=0;j<n;j++)
	       {
		    if(grid[i][j]!=-1&&grid[i][j]!=-2&&i!=n-1&&i!=n-1)
		    {
			 if(grid[i][j]!=2&&grid[i][j]%2==0)
			 {
			 
			      moves=moves+grid[i][j]/2;
			      printf("%d\n",moves);
			      printf("even%d\n",moves);
			      grid[i][j]=-10;
			      crack_even(i,j,n);
			 }
			 else if(grid[i][j]!=2&&prime[grid[i][j]]==-1)
			 {

			      moves=moves+(grid[i][j]+3)/2;
			      printf("%d\n",moves);
			      printf("odd%d\n",moves);
			      grid[i][j]=-10;
			      crack_odd(i,j,n);
			 }
			 else
			 {
			      moves+=prime_ch[grid[i][j]]-1;
			      printf("%d\n",moves);
			 }
		    }
		 
	       }
	  }
	  printf("%d\n",moves);


	  t--;
     }
     return 0;
}

void crack_odd(int i,int j,int n)
{
	  printf("oddffj=%d",j);
	 

     int m,k;
	  printf("%d\n",moves);
     for(m=0;m<n;m++)
     {
	  for(k=0;k<n;k++)
	  {
	       printf("%d ",grid[m][k]);
	  }
	  printf("\n");
     }
     printf("\n");
     
     if(j+1<n)
     {
	  if(grid[i][j+1]!=2&&prime[grid[i][j+1]]==-1&&grid[i][j+1]%2!=0)
	  {
	       grid[i][j+1]=-1;
	       crack_odd(i,j+1,n);
	  }
     }
     if(i+1<n)
     {
	  if(grid[i+1][j]!=2&&prime[grid[i+1][j]]==-1&&grid[i+1][j]%2!=0)
	  {
	       grid[i+1][j]=-1;
	       crack_odd(i+1,j,n);
	  }
     }
     if(j-1>=0&&grid[i][j-1]!=-10)
     {
	  if(grid[i][j-1]!=2&&prime[grid[i][j-1]]==-1)
	  {printf("ffj=%d",j);
	       grid[i][j-1]=-1;
	       crack_odd(i,j-1,n);
	  }
     }
     return;

}

void crack_even(int i,int j,int n)
{
     int m,k;
	  printf("evenffj=%d",j);
	       
	  printf("%d\n",moves);
     for(m=0;m<n;m++)
     {
	  for(k=0;k<n;k++)
	  {
	       printf("%d ",grid[m][k]);
	  }
	  printf("\n");
     }
     printf("\n");

     if(j<0)
     return;
     
     if((j-1)>=0&&grid[i][j-1]!=-10)
     {
	  if(grid[i][j-1]%2==0&&grid[i][j-1]!=2)
	  {
	  printf("j=j=j=%d",j);
	  printf("ff");
	       grid[i][j-1]=-2;
	       crack_even(i,j-1,n);
	  }
     }
	

     if(j+1<n)
     {
	  if(grid[i][j+1]%2==0&&grid[i][j+1]!=2)
	  {
	       grid[i][j+1]=-2;
	       crack_even(i,j+1,n);
	  }
	 
     }
     if(i+1<n)
     {
	  if(grid[i+1][j]%2==0&&grid[i+1][j]!=2)
	  {
	       grid[i+1][j]=-2;
	       crack_even(i+1,j,n);
	  }
	 
     }
     return;
}

