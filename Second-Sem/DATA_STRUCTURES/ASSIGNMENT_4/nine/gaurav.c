#include<stdio.h>
typedef struct list
{
     int group;
     int parent;
}
node;

int n;
node arr[1000];


int are_enemy(int x,int y)
{
     if (arr[x].parent!=arr[y].parent)
	  return 0;
    
     if(arr[x].group!=arr[y].group)
	  return 1;
     return 0;
}

int are_friend(int x,int y)
{
     if (arr[x].parent!=arr[y].parent)
	  return 0;
    
     if(arr[x].group==arr[y].group)
	  return 1;

     return 0;
}


void set_friend(int x,int y)
{
     int i,type,flag=0;
     int p=arr[x].parent;
     if(are_enemy(x,y)==1)
     {
	  printf("-1\n");
	  return;
     }

     type=arr[y].parent;
     for(i=0;i<=n;i++)
     {
	  if(arr[i].parent==p)
	  {
	       arr[i].parent=arr[y].parent;
	      arr[i].group=(arr[i].group+arr[y].group)%2;

	  }
     }
}

void set_enemy(int x,int y)
{
     int i,type,p;
     p=arr[x].parent;
     if(are_friend(x,y)==1)
     {
	  printf("-1\n");
	  return;
     }
     type=arr[y].parent;

     for(i=0;i<=n;i++)
     {
	  if(arr[i].parent==p)
	  {
	       arr[i].parent=arr[y].parent;
	       arr[i].group=(arr[i].group+arr[y].group+1)%2;
	  }
     }
}




int main()
{
     int ans;
     int i,x,y,c;
   
     scanf("%d",&n);
     for(i=0;i<=n;i++)
     {
	  arr[i].group=0;
	  arr[i].parent=i;
     }
     while(1)
     {
	  scanf("%d%d%d",&c,&x,&y);
	  if(c==0)
	       return 0;
	  switch(c)
	  {
	       case 1:
		    set_friend(x,y);
		    break;
	       case 2:
		    set_enemy(x,y);
		    break;
	       case 3:
		    ans=are_friend(x,y);
		    printf("%d\n",ans);
		    break;
	       case 4:
		    ans=are_enemy(x,y);
		    printf("%d\n",ans);
		    break;
	  }
     }
}

