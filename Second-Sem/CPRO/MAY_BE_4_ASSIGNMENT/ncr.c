#include<stdio.h>

int result(int n,int r);
int p=1;
int main()
{
int n,res,r,x,y;
printf("ENTER VALUES FOR N AND R\n");
scanf("%d %d",&x,&y);
res=result(x,y);
printf("RESULT=%d\n",res);
return 0;
}

int result(int n,int r)
{
printf("%d\n",p);
p++;
if(n<=r)
{
return 1;
}
else if(r==1)
{
return n;
}
else
return(result(n-1,r-1)+result(n-1,r));

}



