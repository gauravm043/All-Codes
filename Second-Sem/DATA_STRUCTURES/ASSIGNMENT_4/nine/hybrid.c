//------------------------------------------------------------------------------------------------------------------------//

/*                                           CODE DEVELOPED FOR FRIENDS
					     					
					     	 BY-GAURAV MISHRA
											 										            IIIT-HYDERABAD

																	  						  										*/

//-----------------------------------------------------------------------------------------------------------------------//




#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct list
{
     int group;
     int parent;
}
node;


int n;
node arr[2000000];
int u,v;
int check_set(int i);
void JOIN_IT(int p1,int p2);


int are_enemy(int x,int y)
{
     int p,q;
     q=check_set(v);
     p=check_set(u);
     if(p==q && arr[u].group!=arr[v].group)
	  return 1;
     else 
	  return 0;
}
int are_friend(int x,int y)
{ 
     int p,q;
     p=check_set(u);
     q=check_set(v);
     if(p==q && arr[u].group==arr[v].group)
	  return 1;
     else 
	  return 0;
}


void set_friend(int x,int y)
{
     int p,q;

     q=check_set(v);
     p=check_set(u);
     if(arr[u].parent==arr[v].parent && arr[u].group!=arr[v].group)
	  printf("-1\n");
     else
     {
	  JOIN_IT(p,q);
	  arr[p].group=(arr[u].group+arr[v].group)&1;
     }   

}

void set_enemy(int x,int y)
{ 
     int p,q;
     p=check_set(u);
     q=check_set(v);
     if(arr[u].group==arr[v].group && arr[u].parent==arr[v].parent)
	  printf("-1\n");
     else
     {
	  JOIN_IT(p,q);
	  arr[p].group=(arr[u].group+arr[v].group+1)&1;
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
	  scanf("%d%d%d",&c,&u,&v);
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
int check_set(int i)
{
     int ans;
     int temp;
     if(arr[i].parent==i)
	  return i;
     temp=arr[i].parent;
     ans=check_set(arr[i].parent);
     arr[i].parent=ans;
     arr[i].group=(arr[i].group+arr[temp].group)&1;
    
     return ans;
}
void JOIN_IT(int p1,int p2)
{
     arr[p1].parent=p2;
}

