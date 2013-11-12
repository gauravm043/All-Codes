//+++++++++++++++++++++++++++++//
//       Udyan Khurana         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: Bloom Filter 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define PROB_FALSE 0.001 	//Fixed probability = 0.10%
//K is fixed at 10 as p=(0.5)^k
//according to formula: n=km/ln(2)=14.43m
int bitarr[10000000],found=0,notfound=0;
char numarr[1000000][30];
unsigned int rotateleft(int h, int r)	//Rotate left h by r bits
{	unsigned int x=(h<<r)|(h>>(32-r));
	return x;
}
unsigned int murmurhash3_32(char key[],int size)	//MurmurHash 3: key=input value
{	unsigned int i,c1=0xcc9e2d51,c2=0x1b873593,r1=15,r2=13,m=5,n=0xe6546b64,hash,k;	//these values are constant for 32bit hashing 
	hash=100;	//100 used as a random seed value, can use any other also
	for(i=0;i<strlen(key);i++)
	{	k=key[i]^0x4c143593;
		k*=c1;
		k=rotateleft(k,r1);
		k*=c2;
		hash^=k;
		hash=rotateleft(hash,r2);
		hash=hash*m+n;
	}
	hash^=hash>>16;		//HASH FINALIZER STARTS
	hash*=0x85ebca6b;	
	hash^=hash>>13;
	hash*=0xc2b2ae35;
	hash^=hash>>16;		//HASH FINALIZER ENDS
	hash=hash%size;	
	return hash;
}
unsigned int fnv1(char key[],int size)
{	unsigned int i,hash,offset_basis=2166136261,FNV_prime=16777619;	//these values are constant for 32-bit hashing
	hash=offset_basis;
	for(i=0;i<strlen(key);i++)
	{	hash^=key[i];
		hash=hash*FNV_prime;
	}
	hash=hash%size;	
	return hash;
}
unsigned int jenkins_hash(char key[],int size)
{	unsigned int x=0,hash=0,i=0;
	for(i=0;i<strlen(key);i++)
	{	hash+=key[i];
		hash+=(hash<<10);
		hash^=(hash>>6);
	}
	hash+=(hash<<3);
	hash^=(hash>>11);
	hash+=(hash<<15);
	hash=hash%size;	
	return hash;
}
unsigned int hash4(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=(m+f+j)/3;
	return hash;
}	
unsigned int hash5(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=(((m+f)/2)+j)/2;
	return hash;
}	
unsigned int hash6(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=(m^f)+j;
	return hash;
}	
unsigned int hash7(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=(m^j)+f;
	return hash;
}	
unsigned int hash8(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=(j^f)+m;
	return hash;
}	
unsigned int hash9(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=m|j+f;
	return hash;
}	
unsigned int hash10(int m,int f,int j)	//m - murmur j - jenkins f - fnv
{	unsigned int hash;	
	hash=j|f+m;
	return hash;
}	
int main()
{	int n,m,i,j=0,q,flag=0;
	double falsecases=0;
	double probfalse;
	unsigned int x,y,z;
	char num[30];
	FILE *fp;
	fp=fopen("brit-a-z.txt","r");
	while(!feof(fp))
		fscanf(fp,"%s",numarr[j++]);
//	scanf("%d",&m);
	n=1150938;
	for(i=0;i<79760;i++)
	{	x=murmurhash3_32(numarr[i],n);
		y=fnv1(numarr[i],n);
		z=jenkins_hash(numarr[i],n);
		bitarr[x]=1;
		bitarr[y]=1;
		bitarr[z]=1;
		bitarr[hash4(x,y,z)]=1;
		bitarr[hash5(x,y,z)]=1;
		bitarr[hash6(x,y,z)]=1;
		bitarr[hash7(x,y,z)]=1;
		bitarr[hash8(x,y,z)]=1;
		bitarr[hash9(x,y,z)]=1;
		bitarr[hash10(x,y,z)]=1;
	}
	printf("Enter your paragraph: \n");
//	scanf("%d",&q);
	char cp;
	char cm;
int ctr=1;
	while(1)
	{	//printf("Enter value to check: ");
		scanf("%s",num);
//		printf("%s ",num);
		scanf("%c",&cm);
		x=murmurhash3_32(num,n);
		y=fnv1(num,n);
		z=jenkins_hash(num,n);
		if(bitarr[x]==1 && bitarr[y]==1 && bitarr[z]==1 && bitarr[hash4(x,y,z)]==1 && bitarr[hash5(x,y,z)]==1 && bitarr[hash6(x,y,z)]==1 && bitarr[hash7(x,y,z)]==1 && bitarr[hash8(x,y,z)]==1 && bitarr[hash9(x,y,z)]==1 && bitarr[hash10(x,y,z)]==1)
		{
		//	strcpy(tmp,num);
			found++;
			for(j=0;j<n;j++)
				if(!(strcmp(num,numarr[j])))
				{	flag=1;
					break;
				}
			if(!flag)
			{
			}

			//printf("Element in set\n");
			flag=0;	
		}
		else
		{
		       if(ctr==1)
		       {
			       printf("\n\n\nWords not there in the dictionary are:\n\n\n");
			       ctr=0;
		       }
			       printf("%s\n",num);
			notfound++;	//printf("Element not in set\n");
		}
		scanf("%c",&cm);
		scanf("%c",&cp);
		if(cm=='\n'&&cp=='\n')
			break;
		else
		{
			ungetc(cp,stdin);
			ungetc(cm,stdin);
		}

	}
	printf("NUMBER OF FLASE OUTPUTS: %0.0lf\n",falsecases);
	probfalse=(falsecases*100)/q;
	printf("PROBABILITY OF FLASE OUTPUTS: %lf %\n",probfalse);
	printf("No. actually there: %d\nNo. actually not there: %d\n",found-(int)falsecases,notfound+(int)falsecases);
	return 0;
}
