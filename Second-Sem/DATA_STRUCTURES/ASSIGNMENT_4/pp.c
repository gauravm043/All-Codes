#include<stdio.h>
#include<stdlib.h>
typedef struct a
{
     int data;
     struct a*next;
     int parent;
}
node;

/* Declarations */

int flag=0;
node*posi_friend[10003]={NULL};
node*arr_friends[10003]={NULL};
node*tailf[10003]={NULL};
node*arr_enemies[10003]={NULL};
void PRINT();

/* Functions */

int are_friends(int x,int y)
{
     node*a=posi_friend[x];
     node*b=posi_friend[y];
     if(x==y)
	  return 1;

     if(a!=NULL&&a->parent==y)
	  return 1;
     if(b!=NULL&&b->parent==x)
	  return 1;
     if(a!=NULL&&b!=NULL&&a->parent==b->parent)
	  return 1;
     return 0;
}

int are_enemies(int x,int y)
{
     node*tmp;
     tmp=arr_enemies[x];
     while(tmp!=NULL)
     {
	  if(tmp->data==y)
	       return 1;
	  tmp=tmp->next;
     }
     tmp=arr_enemies[y];
     while(tmp!=NULL)
     {
	  if(tmp->data==x)
	       return 1;
	  tmp=tmp->next;
     }
     return 0;
}




void set_friend(int x,int y)
{
     int a;
     int b;
     node*m;
     node*new;
     new=(node*)malloc(sizeof(node));

     if(are_friends(x,y)==1)
     {
	  return;
     }
     if(are_enemies(x,y)==1)
     {
	  printf("-1\n");
	  return;
     }


     if(1)
     {
	  if(posi_friend[x]!=NULL&&posi_friend[y]==NULL)
	  {
	       x=posi_friend[x]->parent;
	  }
	  else if(posi_friend[y]!=NULL&&posi_friend[x]==NULL)
	  {
	       y=posi_friend[y]->parent;
	  }
	  if(posi_friend[y]==NULL)
	  {
	       new->data=y;
	       new->parent=x;
	       posi_friend[y]=new;
	       new->next=arr_friends[x];
	       arr_friends[x]=new;
	       if(arr_friends[x]->next==NULL)
	       {
		    tailf[x]=new;
	       }
	  }
	  else
	  {

	       node*tmp;
	       node*t;
	       int old;
	       m=posi_friend[y];
	       old=m->parent;
	       x=posi_friend[x]->parent;
	       t=tailf[x];
	       tmp=arr_friends[m->parent];
	       t->next=tmp;
	       while(tmp!=NULL)
	       {
		    tmp->parent=x;
		    tailf[x]=tmp;
		    tmp=tmp->next;
	       }
	       arr_friends[old]=NULL;
	  }

     }
}

void set_enemies(int x,int y)
{
     int gaurav;

     if(are_friends(x,y)==1)
     {
	  printf("-1\n");
	  return;
     }

     if(are_enemies(x,y)==1)
	  return;

     if(1)
     {
          node*new;
          new=(node*)malloc(sizeof(node));
	
	  new->data=y;
	  new->next=arr_enemies[x];
	  arr_enemies[x]=new;

	  node*new2;
	  new2=(node*)malloc(sizeof(node));
	  new2->data=x;
	  new2->next=arr_enemies[y];
	  arr_enemies[y]=new2;

	  if(posi_friend[x]==NULL)
	       gaurav=x;
	  else
	  {
	       new=posi_friend[x];
	       gaurav=new->parent;
	  }

	  new=arr_friends[gaurav];
	  while(new!=NULL)
	  {
	  new2=(node*)malloc(sizeof(node));
	  new2->data=new->data;
	  new2->next=arr_enemies[y];
	  arr_enemies[y]=new2;
	  new=new->next;
	  }
	  if(posi_friend[y]==NULL)
	       gaurav=y;
	  else
	  {
	       new=posi_friend[y];
	       gaurav=new->parent;
	  }

	  new=arr_friends[gaurav];
	  while(new!=NULL)
	  {
	  new2=(node*)malloc(sizeof(node));
	  new2->data=new->data;
	  new2->next=arr_enemies[x];
	  arr_enemies[x]=new2;
	  new=new->next;
	  }




	 
	 

     }
}







void print()
{
     int i,f;
     node*tmp;
     for(i=1;i<=10;i++)
     {
	  f=0;
	  tmp=arr_friends[i];
	  while(tmp!=NULL)
	  {
	       f=1;
	       printf("-->%d  ( %d ) ",tmp->data,tmp->parent);
	       tmp=tmp->next;
	  }
	  if(f==1)
	       printf("\n");
     }
}




int main()
{
     int n,i;
     int a;
     node*u;

     scanf("%d",&n);
     int c=1,x=1,y=1;
/*     for(i=0;i<=n;i++)
     {
	  u=(node*)malloc(sizeof(node));
	  u->data=i;
	  u->next=arr_friends[i];
	  arr_friends[i]=u;
	  u->parent=i;
	  tailf[i]=u;
     }*/
//     print();

     while(1)
     {
	  scanf("%d%d%d",&c,&x,&y);
	  if(c==0&&x==0&&y==0)
	       return 0;
	  switch(c)
	  {
	       case 1:
		    set_friend(x+1,y+1);
//		    print();
//		    printf("\n\n\n\n");
//		    PRINT();
		    break;
	       case 2:
		    set_enemies(x+1,y+1);
//		    print();
//		    printf("\n\n\n\n");
//		    PRINT();
		    break;
	       case 3:
		    a=are_friends(x+1,y+1);
		    if(a==1)
			 printf("1\n");
		    else
			 printf("0\n");
		    break;
	       case 4:
		    a=are_enemies(x+1,y+1);
		    if(a==1)
			 printf("1\n");
		    else
			 printf("0\n");
		    break;
	  }

     }
}

void PRINT()
{
     int i,f;
     node*tmp;
     for(i=0;i<10;i++)
     {
	  f=0;
	  tmp=arr_enemies[i];
	  while(tmp!=NULL)
	  {
	       f=1;
	       printf("--->>%d (%d) ",tmp->data,i);
	       tmp=tmp->next;
	  }
     
     if(f)
	  printf("\n");
     }
}

