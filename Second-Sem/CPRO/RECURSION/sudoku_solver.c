#include<stdio.h>
#include<math.h>
int arr[20][20];
int UNI=1;
int R;
void solve(int a,int b,int c);
int check_it(int a,int b,int c);
int main()
{
    int n,i,j,ch1=0,ch2=0;
    scanf("%d",&n);
    R=sqrt(n);
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    scanf("%d",&arr[i][j]);
	}
    }
    /*SOLVING*/
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    if(arr[i][j]==0)
	    {
		ch1=i;
		ch2=j;
		solve(i,j,n);
	    }
	}
    }

    if(arr[ch1][ch2]==0)
    {
	printf("YOU HAVE ENTERED AN INVALID SUDOKU\n");
	return 0;
    }

    /*SOLVED SUDOKU*/
    printf("SOLVED SUDOKU IS=\n");
    for(i=0;i<n;i++)
    {
	for(j=0;j<n;j++)
	{
	    printf("%d ",arr[i][j]);
	}
	printf("\n");
    }
    return 0;
}

void solve(int i,int j,int n)
{
    int count=0;
    int flag=0;
    int check=0,p,q;
    lb:
    while(check==0)
    {
	count=count+1;
	if(count==n+1)
	{
	    UNI=0;
	    arr[i][j]=0;
	    return;
	}
	arr[i][j]=count;
	check=check_it(i,j,n);
    }
    for(p=0;p<n;p++)
    {
	for(q=0;q<n;q++)
	{
	    if(arr[p][q]==0)
	    {
		solve(p,q,n);
		if(UNI==0)
		{
		    UNI=1;
		    flag=1;
		    break;
		}
	    }
	}
	if(flag==1)
	    break;
    }

    if(flag==1)
    {
	flag=0;
	check=0;
	goto lb;
    }
    else
	return;
}

int check_it(int i,int j,int n)
{
    if(arr[i][j]>n)
	return 0;
    int p,q,row,col,c;
    c=arr[i][j];
    for(p=0;p<n;p++)
    {
	if(p!=j)
	{
	    if(c==arr[i][p])
		return 0;
	}

	if(p!=i)
	{
	    if(c==arr[p][j])
		return 0;
	}
    }

    /*CHECKING BOXES*/
    for(p=0;p<n;p=p+R)
    {
	for(q=p;q<p+R;q++)
	{
	    if(i==q)
	    {
		row=p;
	    }
	    if(j==q)
	    {
		col=p;
	    }
	}
    }

    for(p=row;p<row+R;p++)
    {
	for(q=col;q<col+R;q++)
	{
	    if((p!=i)&&(q!=j))
	    {
		if(c==arr[p][q])
		    return 0;
	    }
	}
    }
    return 1;
}

