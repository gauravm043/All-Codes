#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct tree
{
     char c;
     int f;
     int v;
     struct tree*left;
     struct tree*right;
}
node;

int bits=0;
int SIZE=-1;
int arr[100]={0};
node*minheap[1000];
int fre[300]={0};
int cmin=0;
void print(node*a);

void insert_min(node*d)
{
     cmin++;
     minheap[cmin]=d;
     int i,p;
     node*tmp;
     i=cmin;
     while(i>1)
     {
	  p=i/2;
	  if(p>0&&minheap[p]->f>minheap[i]->f)
	  {
	       tmp=minheap[i];
	       minheap[i]=minheap[p];
	       minheap[p]=tmp;
	       i=p;
	  }
	  else
	       break;
     }
}
void sd_min()
{
     int i=1;
     int min;
     node*tmp;
     while(i<=cmin/2 &&(minheap[i]->f>minheap[2*i]->f||minheap[i]->f>minheap[2*i+1]->f))
     {
	  min=minheap[2*i]->f<=minheap[2*i+1]->f?2*i:2*i+1;
	  tmp=minheap[i];
	  minheap[i]=minheap[min];
	  minheap[min]=tmp;
	  i=min;
     }
}

node* del_min()
{
     node*min;
     min=minheap[1];
     minheap[1]=minheap[cmin];
     cmin--;
     sd_min();
     return min;
}


int main()
{
     char c;
     float unique=0;
     int i,n=-1;
     int b;
     char bb;
     float ans;
     node*new;
     node*new1;
     node*new2;
	  c=getchar();
     while(c!=EOF)
     {
	  bb=c;
  //        printf("%d\n",c);
	       n++;
	       fre[c]++;
	  c=getchar();
	  //bb=c;
     }
//     printf("-------%d\n",bb);
     fre[bb]--;
     for(i=0;i<=256;i++)
     {
	  if(fre[i]!=0)
	  {
	       new=(node*)malloc(sizeof(node));
	       new->c=(char)i;
	       new->f=fre[i];
	       new->left=NULL;
	       new->right=NULL;
	       new->v=1;
	       insert_min(new);
	  }
     }
     for(i=0;i<=256;i++)
     {
	  if(fre[i]!=0)
	       unique++;
     }

     b=log(unique)/log(2);
     if(n&3!=0)
     {
	  b=b+1;
     }


//     printf("--%d\n",b);

  //   printf("%d\n",n*4);

     while(cmin!=1)
     {
	  new1=del_min();
	  new2=del_min();
	  new=(node*)malloc(sizeof(node));
	  new->f=new1->f+new2->f;
	  new->left=new1;
	  new->right=new2;
	  new->c='d';
	  new->v=0;
	  insert_min(new);
     }
     print(new);
     ans=(float)bits/(n*b)*100;

     printf("%0.2f\n",ans);
     return 0;
}
void print(node*root)
{
     int i;
     if(root->left==NULL&&root->right==NULL)
     {
	  bits+=(SIZE+1)*fre[root->c];
	  printf("%c :",root->c);
	  for(i=0;i<=SIZE;i++)
	       printf("%d",arr[i]);
	  printf("\n");
	  --SIZE;
	  return;
     }

     arr[++SIZE]=0;
     print(root->left);
     arr[++SIZE]=1;
     print(root->right);
     --SIZE;
}

