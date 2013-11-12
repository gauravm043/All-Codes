#include<stdio.h>
#include<math.h>
int main()
{
     int n,a,b;
     int player1=0,player2=0;
     int lead1=0,lead2=0;
     scanf("%d",&n);
     while(n--)
     {
	  scanf("%d%d",&a,&b);
	  player1+=a;
	  player2+=b;
	  if(player1-player2>0)
	       if(lead1<player1-player2)
		    lead1=player1-player2;

	  if(player1-player2<0)
	       if(lead2<player2-player1)
		    lead2=player2-player1;
     }
     if(lead1>lead2)
	  printf("1 %d\n",lead1);
     else
	  printf("2 %d\n",lead2);
     return 0;
}
