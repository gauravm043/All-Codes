#include<stdio.h>
#include<string.h>

char parent[100000];
char temp[40001];
int fre_child[27]={0};
int fre_parent[27]={0};

int main()
{
     int t,i;
     int number;
     scanf("%d",&t);
     while(t--)
     {
	  
	  for(i=0;i<=25;i++)
	  {
	       fre_child[i]=0;
	       fre_parent[i]=0;
	  }
	  
	  scanf("%s",parent);
	  scanf("%s",temp);
	  strcat(parent,temp);
	  
	  for(i=0;i<strlen(parent);i++)
	       fre_parent[parent[i]-'a']++;
	  
	  scanf("%d",&number);

	  while(number--)
	  {
	       scanf("%s",temp);
	       
	       for(i=0;i<strlen(temp);i++)
		    fre_child[temp[i]-'a']++;
	  }

	  /* CHECKING */

	  for(i=0;i<=25;i++)
	  {
	       if(fre_child[i]!=0)
	       {
		    if(fre_parent[i]<fre_child[i])
		    {
			 break;
		    }
	       }
	  }

	  if(i==26)
	       printf("YES\n");
	  else
	       printf("NO\n");

     }
     return 0;
}
