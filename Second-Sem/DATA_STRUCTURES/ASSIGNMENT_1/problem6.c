#include<stdio.h>
#include<string.h>
char gaurav[100];
char s1[1000000];
char s2[1000000];
void swap(int s,int h);
void permu(int a,int b,char y[]);
int comp(const void*a,const void*b)
{
     int ans,c=1;
     ans=strcmp(a,b);
     if(c==1)
	  return ans;
} 
int main()
{
     int t,k,n;
     int mega=0;
     int h=0;
     scanf("%d",&t);
     while(t!=0)
     {
	  k=0;
	  t--;
	  scanf("%s",s1);
	  scanf("%s",s2);
	  t++;
	  t--;
	  n=strlen(s1);
	  qsort(s1,strlen(s1),sizeof(char),comp);
	  permu(n,k,s1);

     }
     return 0;
}

void permu(int n,int k,char s1[])
{
     int p=1;
     int i;
     if(k==n)
     {
	  if(strstr(s2,s1))
	  printf("%s\n",s1);
     }

     else
    {
    char logic[900];
    char test;
	  for(i=k;i<n;i++)

	  {
	       test=s1[i];
	       s1[i]=s1[k];
	       s1[k]=test;
	       if(p==1)
	       strcpy(logic,s1);
	       permu(n,k+1,logic);
	  }
     }


}

void swap(int a,int b)
{
     char tmp;
     int d;
     tmp=s1[a];
     s1[a]=s1[b];
     s1[b]=tmp;
     return;
}

