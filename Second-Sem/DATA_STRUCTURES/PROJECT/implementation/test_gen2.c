//+++++++++++++++++++++++++++++//
//       Udyan Khurana         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	
	int test=100000,q;
	time_t t;
	printf("%d\n",test);
	srand((unsigned) time(&t));
	while(test--)
		printf("%d\n",rand()%100000000);
	q=rand()%100000;
	printf("%d\n",q);
	while(q--)
		printf("%d\n",rand()%100000000);
	return 0;
	

}

