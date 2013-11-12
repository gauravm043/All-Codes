#include<stdio.h>
typedef struct node{
     int parent;
     int type;
}node;
node set[1000100];
int findset(int i)
{
     if(set[i].parent==i)
	  return i;
     int temp=set[i].parent;
     int retvalue=findset(set[i].parent);
     set[i].parent=retvalue;
     set[i].type=(set[i].type+set[temp].type)&1;
     return retvalue;
}
void Union(int p1,int p2)
{
     set[p1].parent=p2;
}
int main()
{
     int n,rel,u,v,i,k,a,b;
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
	  set[i].parent=i;
	  set[i].type=0;
     }
     while(1)
     {
	  scanf("%d%d%d",&rel,&u,&v);
	  if(rel==0 && u==0 && v==0)
	       return 0;
	  if(rel==1)
	  {
		    a=findset(u);
		    b=findset(v);
	       if(set[u].parent==set[v].parent && set[u].type!=set[v].type)
		    printf("-1\n");
	       else
	       {
		    Union(a,b);
		    set[a].type=(set[u].type+set[v].type)&1;
//		    set[u].type=(set[u].type+set[v].type)%2;
//		    printf("u : %d v :%d  u : parent : %d  v : parent : %d\n",u,v,set[u].type,set[v].type);
//		    printf("ofvefv %d \n",set[0].type);
	       }
	  }
          else if(rel==2)
	  {
		    a=findset(u);
		    b=findset(v);
	       if(set[u].type==set[v].type && set[u].parent==set[v].parent)
		    printf("-1\n");
	       else
	       {
		    Union(a,b);
		    set[a].type=(set[u].type+set[v].type+1)&1;
//		    set[u].type=(set[u].type+set[v].type+1)%2;
	       }
	  }
	  else if(rel==3)
	  {
		    a=findset(u);
		    b=findset(v);
	       if(a==b && set[u].type==set[v].type)
		    printf("1\n");
	       else 
		    printf("0\n");
	  }
	  else if(rel==4)
	  {
		    a=findset(u);
		    b=findset(v);
	       if(a==b && set[u].type!=set[v].type)
		    printf("1\n");
	       else 
		    printf("0\n");
	  }
	  for(i=0;i<n;i++)
	       printf("i : %d parent : %d type : %d\n",i,set[i].parent,set[i].type);
	  printf("\n\n");
     }
     return 0;
}
