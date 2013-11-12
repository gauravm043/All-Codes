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
int numarr[10000000],bitarr[10000000],found=0,notfound=0;
unsigned int rotateleft(int h, int r)	//Rotate left h by r bits
{	unsigned int x=(h<<r)|(h>>(32-r));
	return x;
}
unsigned int murmurhash3_32(int key,int size)	//MurmurHash 3: key=input value
{	unsigned int c1=0xcc9e2d51,c2=0x1b873593,r1=15,r2=13,m=5,n=0xe6546b64,hash,k;	//these values are constant for 32bit hashing 
	hash=100;	//100 used as a random seed value, can use any other also
	k=key;
	k*=c1;
	k=rotateleft(k,r1);
	k*=c2;
	hash^=k;
	hash=rotateleft(hash,r2);
	hash=hash*m+n;
	hash^=hash>>16;		//HASH FINALIZER STARTS
	hash*=0x85ebca6b;	
	hash^=hash>>13;
	hash*=0xc2b2ae35;
	hash^=hash>>16;		//HASH FINALIZER ENDS
	hash=hash%size;	
	return hash;
}
unsigned int fnv1(int key,int size)
{	unsigned int hash,offset_basis=2166136261,FNV_prime=16777619;	//these values are constant for 32-bit hashing
	hash=offset_basis;
	hash^=key;
	hash=hash*FNV_prime;
	hash=hash%size;	
	return hash;
}
unsigned int jenkins_hash(int key,int size)
{	unsigned int x=0,hash=0,i=0;
	for(i=8;i<=32;i+=8)
	{	x=key<<(32-i);
		x=x>>24;
		hash+=x;
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
{	int n,m,i,j,q,num,flag=0,falsecases=0;
	float probfalse;
	unsigned int x,y,z;
	scanf("%d",&m);
	n=14.43*m+1;
	for(i=0;i<m;i++)
	{	scanf("%d",&numarr[i]);
		x=murmurhash3_32(numarr[i],n);
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
	//printf("Enter no. of queries: ");
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{	//printf("Enter value to check: ");
		scanf("%d",&num);
		x=murmurhash3_32(num,n);
		y=fnv1(num,n);
		z=jenkins_hash(num,n);
		if(bitarr[x]==1 && bitarr[y]==1 && bitarr[z]==1 && bitarr[hash4(x,y,z)]==1 && bitarr[hash5(x,y,z)]==1 && bitarr[hash6(x,y,z)]==1 && bitarr[hash7(x,y,z)]==1 && bitarr[hash8(x,y,z)]==1 && bitarr[hash9(x,y,z)]==1 && bitarr[hash10(x,y,z)]==1)
		{	found++;
			for(j=0;j<n;j++)
				if(num==numarr[j])
				{	flag=1;
					break;
				}
			if(!flag)
				falsecases++;
			//printf("Element in set\n");
			flag=0;	
		}
		else
			notfound++;	//printf("Element not in set\n");
	}
	printf("NUMBER OF FLASE OUTPUTS: %d\n",falsecases);
	probfalse=(falsecases*100)/q;
	printf("PROBABILITY OF FLASE OUTPUTS: %.2f %\n",probfalse);
	printf("No. actually there: %d\nNo. actually not there: %d\n",found-falsecases,notfound+falsecases);
	return 0;
}
