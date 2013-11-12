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
	int test=100000,q,limit=20;
	time_t t;
	printf("%d\n",test);
	srand((unsigned) time(&t));
	while(test--)
	{
		limit=rand()%18+1;
		while(limit--)
			printf("%c",rand()%26+97);
		printf("\n");
	}
	q=rand()%100000;
	printf("%d\n",q);
	while(q--)
	{
		limit=rand()%18+1;
		while(limit--)
			printf("%c",rand()%26+97);
		printf("\n");
	}

	return 0;
}
