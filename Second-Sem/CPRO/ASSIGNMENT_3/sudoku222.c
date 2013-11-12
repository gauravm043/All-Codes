#include<stdio.h>
#include<math.h>
void please()
{
	printf("please accept  my program");
	return;
}

int main()
{
	long long int r,counter,flag,j,k,h,g,s1,counter2=0,c,n,t,sum=0,i,s,s2,zero,zero2,br,bc,sqroot;
	long long int sudoku[100][100],dis[100];
	scanf("%lld",&t);
lb:
	while(t!=0)
	{
		flag=1;
		scanf("%lld",&n);
		if(n==1)
		{
			scanf("%lld",&sudoku[0][0]);
			printf("YES\n");
			t--;
			goto lb;
		}
		else
		{
		for(i=0;i<n;i++)
		{
		
			for(j=0;j<n;j++)
			{
				scanf("%lld",&sudoku[i][j]);
				if(sudoku[i][j]>n||sudoku[i][j]<1)
				{
					flag=0;
			
				}
		
			}
		}
		}
		i=0;j=0;
	        

		if(flag==1)
		{

		for(r=0;r<n;r++)
		{
			if(flag==0)
				break;
			for(c=0;c<n;c++)
			{
				if(flag==0)
					break;
				for(k=0;k<n;k++)
				{
					if(c!=k)
					{
					if((sudoku[r][c]==sudoku[r][k]))
					{
						flag=0;
						break;
					}

					if(sudoku[c][r]==sudoku[k][r])
					{
						flag=0;
						break;
					}
					}
				}
			}
		}
		}

                 if(flag==1)
		{
		zero=0,zero2=0,counter=0,counter2=0;
		sqroot=sqrt(n);
		s=s2=sqroot;
		int mega=0,sum=0,mm=0;
		if(flag==1)
		{
			int p=0,check=0,mm=0;
                        for(i=zero;i<s;i++)
			{
				if(flag==0||mega==n)
					break;
				
				counter=counter+1;
				for(j=zero2;j<s2;j++)
				{
					
					/*printf("%lld  ",sudoku[i][j]);*/
					counter2=counter2+1;
					/*sum=sum+sudoku[i][j];*/
					dis[mm]=sudoku[i][j];
					mm++;
				}

				if(counter2==n)
				{
				   
					for(h=0;h<n;h++)
				    {
					    for(g=0;g<n;g++)
					    {
						    if(dis[h]==dis[g]&&h!=g)
						    {
							    flag=0;
							    break;
						    }
					    }
				    }
				    mm=0;
				}





				
				/*if(counter2==n)
				{
					mega++;
					printf("%lld\n\n",sum);
				if(sum!=n*(n+1)/2)
				{
			          
					flag=0;
				        break;
				}
				}*/
				
				if(counter==sqroot&&counter2==n&&s2!=n)
				{
				
					sum=0;
					i=p-1;
					zero2=s2;
					s2=s2+sqroot;
					j=zero2;
					counter=counter2=0;
				}

				if(counter==sqroot&&counter2==n&&s2==n&&s!=n)
				{
					sum=0;
					s2=0;
					i=s-1;
					zero=s;
					s=s+sqroot;
					zero2=s2;
					s2=s2+sqroot;
					j=zero2;
					p=p+sqroot;
					check++;
					counter=counter2=0;
				}
				if(mega==n)
				{
					mega=0;
					break;
				}

				
			}
	
		}
		}

		if(flag==1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		t--;
	}
	return 0;
}



















						
						





































