#include<stdio.h>
#include<math.h>


int main()
{
	long long int r,counter,counter2,c,n,t,sum=0,i,j,ch1,f,ch=1,mc=0,s,s2,zero,zero2,br,bc,sqroot;
	scanf("%lld",&t);
        lb:
	while(t!=0)
	{
		mc=1;
		scanf("%lld",&n);
		long long int sudoku[n][n];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				ch1=1;
				scanf("%lld",&sudoku[i][j]);
				if(sudoku[i][j]>n&&sudoku[i][j]>0)
				{
					ch1=0;
				}
			}
		}


		if(ch1==0)
		{
			printf("NO\n");
			t--;
			mc=0;
			goto lb;
		}





	ch=1;
		for(r=0;r<n;r++)
		{
			for(c=0;c<n;c++)
			{
				for(f=0;f<n;f++)
				{
					if((c!=f)&&sudoku[r][c]==sudoku[r][f])
					{
						printf("NO\n");
						t--;
						ch=0,mc=0;
						goto lb;
					}
					if((c!=f)&&sudoku[c][r]==sudoku[f][r])
					{
						printf("NO\n");
					        t--;
						ch=0,mc=0;
						goto lb;
					}

				}
			}
		}


                zero=0,zero2=0,counter=0,counter2=0;
		sqroot=sqrt(n);
		mc=0;
		s=s2=sqroot;
		if(ch==1)
		{
			for(i=zero;i<s;i++)
			{
				counter=counter+1;
				for(j=zero2;j<s2;j++)
				{
					counter2=counter2+1;
					printf("%lld  ",sudoku[i][j]);
				}
				printf("\n");
				
				
				if(counter==sqroot&&counter2==n&&s2!=n)
				{
					i=-1;
					zero2=s2;
					s2=s2+sqroot;
					j=zero2;
					counter=counter2=0;
				}

				if(counter==sqroot&&counter2==n&&s2==n&&s!=n)
				{
					s2=0;

					i=-1;
					zero=s;
					s=s+sqroot;
					zero2=s2;
					s2=s2+sqroot;
					j=zero2;
					counter=counter2=0;
				}
				if(s==n&&s2==n)
					break;
				
			}
			printf("\n");
	
		}



		
		if(mc==1)
		{printf("YES\n");
		printf("\n");}
		t--;
	}
	return 0;
}



















						
						





































