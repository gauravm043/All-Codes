#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct trie
{
     char v;
     int valid;
     struct trie*child[27];
}
node;

void display(node*r);
char arr[100];
int posi=0;
char ans[100];
int k=0;

void insert(node*root)
{
     if(posi==strlen(arr))
     {
	  root->valid=1;
	  return;
     }
     int next;
     node*new;
     if(root->child[arr[posi]-'a']==NULL)
     {
	  new=(node*)malloc(sizeof(node));
	  new->v=arr[posi];
	  root->child[arr[posi]-'a']=new;
     }
     if(root->child[arr[posi]-'a']!=NULL)
     {
	  next=posi;
	  posi++;
	  insert(root->child[arr[next]-'a']);
     }
}

void search(node*root)
{
     int next;
     if(posi==strlen(arr))
     {
	  printf("FOUND\n");
	  return;
     }
     else if(root->child[arr[posi]-'a']==NULL)
     {
	  printf("NOT FOUND\n");
	  return;
     }
     else
     {
	  next=posi;
	  posi++;
	  search(root->child[arr[next]-'a']);
     }
}

void all_words(node*root)
{
     int next;
     if(root->child[arr[posi]-'a']==NULL)
     {
	  printf("NOT FOUND\n");
	  return;
     }
     else
     {
	  ans[k++]=arr[posi];
	  next=posi;
	  posi++;
	  if(posi==strlen(arr))
	  {
	       display(root->child[arr[next]-'a']);
	       return;
	  }
	  else
	       all_words(root->child[arr[next]-'a']);
     }
}

void display(node*root)
{
     int i;
     for(i=0;i<26;i++)
     {
	  if(root->child[i]!=NULL)
	  {
	       ans[k++]=root->child[i]->v;
	       display(root->child[i]);
	  }
     }
     ans[k]='\0';
     if(root->valid==1)
     printf("%s\n",ans);
     k--;
     return;
}



int main()
{
     node*root;
     root=(node*)malloc(sizeof(node));
     int n;
     scanf("%d",&n);
     while(n--)
     {
	  scanf("%s",arr);
	  posi=0;
	  insert(root);
     }

     scanf("%d",&n);
     while(n--)
     {
	  scanf("%s",arr);
	  posi=0;
	  k=0;
	  all_words(root);
     }

     return 0;
}
