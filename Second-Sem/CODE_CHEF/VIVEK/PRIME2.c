#include <stdio.h>
#include <math.h>
 
 
int a[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,137,139,149,151,157,163,167,173};
 
int b[31623] = {0};
int p_count = 0;
int p[31622];
int main()
{
     int i, size, m ,lower, upper, k;
     double div;
     int r[100000] = {0};
     int diff;
     b[0]=1;
     b[1]=1;
     for(i=0; i < 39; i++)
     {
	  m=2*a[i];
	  while(m<31623)
	  {
	       b[m]=1;
	       m = m + a[i];
	  }
     }
     for(i=2; i<31623; i++)
     {
	  if(b[i]==0)
	       p[p_count++] = i;
     }
     scanf("%d", &size);
     while(size--)
     {
	  scanf("%d%d", &lower, &upper);
	  diff = upper - lower +1;
	  for(i=0; i< diff; i++)
	       r[i]=0;
	  if(lower==1)
	       r[0]=1;
	  for(i=0; i<p_count; i++)
	  {
	       if(upper>p[i])
	       {
		    div = (double)(lower)/p[i];
		    k=ceil(div);
		    if(k==1)
			 m=p[i]*2-lower;
		    else
			 m=p[i]*k-lower;
		    while(m < diff)
		    {
			 r[m]=1;
			 m+=p[i];
		    }
	       }
	  }
	  for(i=0; i<diff; i++)
	       if(r[i]==0)
		    printf("%d\n", lower+i);
	  printf("\n");
     }
     return 0;
}