//+++++++++++++++++++++++++++++//
//       Udyan Khurana         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: 
#include<stdio.h>
int arr[10000000];
int main()
{	int test,i=0,q,num;
	int f=0,found=0,notfound=0;
	scanf("%d",&test);
	while(test--)
		scanf("%d",&arr[i++]);
	scanf("%d",&q);
	while(q--)
	{	f=0;
		scanf("%d",&num);
		for(i=0;i<10000000;i++)
		{	if(arr[i]==num)
			{
				f=1;
				found++;
				break;
			}
		}
		if(!f)
			notfound++;
	}
	printf("No. there: %d\nNo. not there: %d\n",found,notfound);
	return 0;
}
