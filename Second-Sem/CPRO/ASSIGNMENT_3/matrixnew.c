#include<stdio.h>
void get (int A[p][q]);
int  multiply(int C[m][n],int B2[p][q]);
int main()
{
	int i,j;
	scanf("%d",&t);
	while(t!=0)
	{
		scanf("%d",&k);
		scanf("%d %d",&con,&q);
		int A[con][q];
		get(A[con][q]);
		scanf("%d %d",&m,&n);
		int B[m][n];
		get(B[m][n]);
		for(i=1;i<=(k-2);i++)
		{
			ret=multiply(A[con][q],B[m][n]);
			scanf("%d %d",&p,&q);
			int B2[p][q];
			get(B2[p][q]);
			multiply(A[con][ret],B2[p][q]);
		}
		t--;
	}
	return 0;
}

void get(int A[p][q])
{
	for(i=0;i<p;i++)
	{
		for(j=0;j<q;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
	return;
}

int multiply(int A[m][n],int B2[p][q])
{
	if(n!=p)
		return -1;
	for(i=0;i<m;i++)
		for(j=0;j<q;j++)
		{







