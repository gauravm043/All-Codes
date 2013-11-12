#include<stdio.h>

int n_min,n_max,heap1[1000000],heap2[1000000];
 //heap1 for minimum and heap2 for maximum


insert_min(int i)
{
   int temp;
   for(i;i>1;i=i/2)
   {
      if(heap1[i]<heap1[i/2])	//condition for swap
      {
	 temp=heap1[i];
	 heap1[i]=heap1[i/2];
	 heap1[i/2]=temp;
      }
      else
	 break;
   }
}


insert_max(int i)
{
   int temp;
   for(i;i>1;i=i/2)
   {
      if(heap2[i]>heap2[i/2])	//condition for swap
      {
	 temp=heap2[i];
	 heap2[i]=heap2[i/2];
	 heap2[i/2]=temp;
      }
      else
	 break;
   }
}

int delete_min()
{
   int temp,tempn,i,k,small,return_value;
   return_value=heap1[1];
   heap1[1]=heap1[n_min];	//make last as first element
   tempn=n_min-1;		//not done n-- becoz this n is to be used in delete max also
   for(i=1;i<=tempn;i++)
   {
      if((2*i)<=tempn)
      {
	 if(heap1[2*i]<heap1[2*i+1])
	 {
	    small=heap1[2*i];
	    k=2*i;
	 }
	 else
	 {
	    small=heap1[2*i+1];
	    k=2*i+1;
	 }

	 /*Now swap small with the parent*/
	 
	 if(heap1[i]>small)
	 {
	    temp=heap1[i];
	    heap1[i]=small;
	    heap1[k]=temp;
	 }
      }
   }
   return return_value;
}   

delete_max()
{
   int temp,tempn,i,k,large,return_value;
   return_value=heap2[1];
   heap2[1]=heap2[n_max];	//make last as first element
   tempn=n_max-1;		//not done n-- becoz this n is to be used in delete max also
   for(i=1;i<=tempn;i++)
   {
      if((2*i)<=tempn)
      {
	 if(heap2[2*i]>heap2[2*i+1])
	 {
	    large=heap2[2*i];
	    k=2*i;
	 }
	 else
	 {
	    large=heap2[2*i+1];
	    k=2*i+1;
	 }

	 /*Now swap small with the parent*/
	 
	 if(heap2[i]<large)
	 {
	    temp=heap2[i];
	    heap2[i]=large;
	    heap2[k]=temp;
	 }
      }
   }
   return return_value;
}   

/*print()
{
   int i;
   for(i=1;i<=n_min;i++)
      printf("%d ",heap1[i]);
   printf("\n");
}*/

int main()
{
   int hash[1000000],i,tc,pro,rec,temp,p,q,sum;
   scanf("%d",&tc);
   while(tc--)
   {
      sum=0;
      for(i=0;i<1000000;i++)
	 hash[i]=0;
      scanf("%d",&pro);
      //i=1;
      n_min=1;
      n_max=1;
      while(pro--)
      {
	 scanf("%d",&rec);
         while(rec--)
	 {
	    scanf("%d",&temp);
	    hash[temp]++;
	    heap1[n_min]=temp;
	    heap2[n_max]=temp;
	    insert_max(n_max);		//insert into max heap
	    insert_min(n_min);		//insert into min heap
	    n_min++;		//no. of elements in a heap as my heap starts from i=1
	    n_max++;
	    //i++;
	 }
	 if(n_min>1&&n_max>1)
	 {
	    p=delete_min();
	    n_min--;
	    while(hash[p]==0)
	    {
	       p=delete_min();
	       n_min--;
	    }
	    q=delete_max();
	    n_max--;
	    while(hash[q]==0)
	    {
	       q=delete_max();
	       n_max--;
	    }
	    hash[p]--;
	    hash[q]--;
	    sum=sum+q-p;
	 }
      }
      printf("%d\n",sum);
   }
   return 0;
}
