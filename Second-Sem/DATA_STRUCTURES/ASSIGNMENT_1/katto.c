#include<stdio.h>
#include<string.h>
char s1[1000000];
char s2[1000000];
void swap(int s,int h);
void permu(char y[],int a,int b);
int comp(const void*a,const void*b)
{
     return strcmp(a,b);
} 
int main()
{
     int t,k,n;
     scanf("%d",&t);
     while(t!=0)
     {
	  k=0;
	  t--;
	  scanf("%s",s1);
	  n=strlen(s1);
	  qsort(s1,strlen(s1),sizeof(char),comp);
	  permu(s1,n,k);

     }
     return 0;
}

void permu(char s1[],int n, int k)
{
     int i;
     if(k==n)
     {
	  printf("%s\n",s1);
     }

     else
    {
	  for(i=k;i<n;i++)

	  {
	       char t;
	       t=s1[i];
		s1[i]=s1[k];
		s1[k]=t;
	       char temp[90];
	       strcpy(temp,s1);
	       permu(temp,n,k+1);
	  }
     }


}

void swap(int a,int b)
{
     char tmp;
     tmp=s1[a];
     s1[a]=s1[b];
     s1[b]=tmp;
     return;
}

