#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int  CH(char s[]);

char stack[1000000];
typedef struct tree
{

     char data[10];
     struct tree*left;
     struct tree*right;
}

node;
void print(node*a);
node*sta[1000000];
int prec[8]={0,0,5,4,0,4,0,6};
int arr[1000000];
char tr[100000][10];



int pop(char a[],int t)
{
     node*new;
     new=(node*)malloc(sizeof(node));
     new->left=sta[t-1];
     new->right=sta[t];
     strcpy(new->data,a);
     sta[t-1]=new;
     return t-1;
}



int main()
{

     char ch[10];
     char c;
     while(1)
     {
	  int m=-1;
	  int j=-1;
	  c='a';
	  while(c!='\n')
	  {
	       scanf("%s",ch);
	       scanf("%c",&c);
	       if((strlen(ch)>1)||(strlen(ch)==1&&(ch[0]>='0'&&ch[0]<='9')))
	       {
		    m++;
		    strcpy(tr[m],ch);
	       }
	       else if(ch[0]=='(')
	       {
		    j++;
		    stack[j]=ch[0];
	       }
	       else if(ch[0]=='+'||ch[0]=='-'||ch[0]=='*'||ch[0]=='/')
	       {
		    if(prec[ch[0]-40]>prec[stack[j]-40])
		    {
			 j++;
			 stack[j]=ch[0];
		    }
		    else
		    {
			 while(stack[j]!=')'&&prec[ch[0]-40]<=prec[stack[j]-40])
			 {
			      m++;
			      tr[m][0]=stack[j];
			      tr[m][1]='\0';
			      j--;
			 }
			 j++;
			 stack[j]=ch[0];
		   
		    }
	       }
	       else if(ch[0]==')')
	       {
		    while(stack[j]!='(')
		    {
		 m++;
		 tr[m][0]=stack[j];
		 tr[m][1]='\0';
			 j--;
		    }
		    j--;
	       }

	  }
	  while(j!=-1)
	  {
	       m++;
	       tr[m][0]=stack[j];
	       tr[m][1]='\0';
	       j--;
	  }

	  int i;
	  int t=-1;
	  for(i=0;i<=m;i++)
	  {
	       if(strlen(tr[i])>1||(tr[i][0]>='0'&&tr[i][0]<='9'))
	       {

		    t++;
		    node*new;
		    new=(node*)malloc(sizeof(node));
		    strcpy(new->data,tr[i]);
		    new->left=NULL;
		    new->right=NULL;
		    sta[t]=new;
	       }
	       else
	       {
		    t=pop(tr[i],t);
	       }
	  }

	  print(sta[0]);

	  printf("\n");
	 
	  c=getchar();
	  if(c==EOF)
	       return 0;
	  else
	       ungetc(c,stdin);


     }
     return 0;
}
int CH(char a[0])
{
     if(strlen(a)>1)
	  return 0;
     if(a[0]=='+'||a[0]=='-'||a[0]=='/'||a[0]=='*')
	  return 1;
     else 
	  return 0;
}
 
void print(node*root)
{
     if(root==NULL)
	  return;
     if(root->data[0]=='+')
     {
	  print(root->left);
	  printf("%s ",root->data);
	  print(root->right);
     }
     else if(root->data[0]=='-')
     {
	  print(root->left);
	  printf("%s ",root->data);
	  if(root->right!=NULL&&CH(root->right->data)==1&&prec[root->right->data[0]-40]==prec['+'-40])
	  {
	  printf("( ");
	  print(root->right);
	  printf(") ");
	  }
	  else
	       print(root->right);
     }
     else if(root->data[0]=='*')
     {
	  if(root->left!=NULL&&CH(root->left->data)==1&&prec[root->left->data[0]-40]<prec['*'-40])
	  {
	       printf("( ");
	       print(root->left);
	       printf(") ");
	  }
	  else
	       print(root->left);
	  printf("%s ",root->data);

	  if(root->right!=NULL&&CH(root->right->data)==1&&prec[root->right->data[0]-40]<prec['*'-40])
	  {
	       printf("( ");
	       print(root->right);
	       printf(") ");
	  }
	  else
	       print(root->right);
     }
     else if(root->data[0]=='/')
     {
	  if(root->left!=NULL&&CH(root->left->data)==1&&prec[root->left->data[0]-40]<prec['/'-40])
	  {
	       printf("( ");
	       print(root->left);
	       printf(") ");
	  }
	  else
	       print(root->left);
	  printf("%s ",root->data);

	  if(root->right!=NULL&&CH(root->right->data)==1)
	  {
	       printf("( ");
	       print(root->right);
	       printf(") ");
	  }
	  else
	       print(root->right);
     }
     else
     {
	  print(root->left);
	  printf("%s ",root->data);
	  print(root->right);
     }
}
