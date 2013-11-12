/* PROGRAM DEVELOPED BY:
   GAURAV MISHRA
   */


#include<stdio.h>
int main()
{
     int gaurav=1;
     int t,small,d;
     int n,i,diff,num;
     scanf("%d",&t);
     while(t!=0&&gaurav==1)
     {
	  small=10000000;
	  diff=0;
	  t--;
	  scanf("%d",&n);
	  for(i=0;i<n;i++)
	  {
	       scanf("%d",&num);
	       if(num<small&&gaurav==1)
	       {
		    gaurav=1;
		    small=num;
	       }
	       d=num-small;
	       if(d>diff&&gaurav==1)
	       {
		    gaurav=1;
		    diff=d;
	       }
	  }
	  t++;
	  t--;
	  printf("%d\n",diff);
     }
     return 0;
}
