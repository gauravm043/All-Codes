#include<stdio.h>
#include<string.h>
char st[1000000];
int main()
{
     int t,ans,j,a1,a2,a3;
     int m,l,i,ch;
     scanf("%d",&t);
     while(t!=0)
     {
	  ans=0;
	  scanf("%s",st);
	  l=strlen(st);
	  for(i=0;i<l;i++)
	  {
	       a1=0;
	       a2=0;
	       a3=0;
	       for(j=i;j<l;j++)
	       {
		    if(st[j]=='a')
			 a1=a1+1;
		    else if(st[j]=='b')
			 a2=a2+1;
		    else if(st[j]=='c')
			 a3=a3+1;
		    else{;}
		    if(a1==a2 && a1!=0)
		    {
			 if(a2==a3)
			 {
			      ans++;
			 }
		    }

	       }
	  }
	  printf("%d\n",ans);
	  t--;
     }
     return 0;
}
