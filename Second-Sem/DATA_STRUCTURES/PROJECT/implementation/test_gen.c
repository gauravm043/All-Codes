//+++++++++++++++++++++++++++++//
//       Udyan Khurana         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: 
#include<stdio.h>
int main()
{	
	int test=100000,q;
	printf("%d\n",test);
	while(test--)
		printf("%d\n",rand()%100000000);
	q=rand()%100000;
	printf("%d\n",q);
	while(q--)
		printf("%d\n",rand()%100000000);
	return 0;
	

}

