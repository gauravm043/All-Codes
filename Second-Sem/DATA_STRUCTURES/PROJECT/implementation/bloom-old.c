//+++++++++++++++++++++++++++++//
//       Udyan Khurana         //
//       IIIT-Hyderabad        //
//+++++++++++++++++++++++++++++//
// Topic: Bloom Filter 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int hash1(int n)
{	return n%50;	}
int hash2(int n)
{	return n%20;	}
int hash3(int n)
{	return n%10;	}
unsigned int rotateleft(int h, int r)	//Rotate left h by r bits
{	unsigned int x=(h<<r)|(h>>(32-r));
	return x;
}
unsigned int murmurhash3_32(int key)	//MurmurHash 3: key=input value
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
	return hash;
}
unsigned int fnv1(int key)
{	unsigned int hash,offset_basis=2166136261,FNV_prime=16777619;	//these values are constant for 32-bit hashing
	hash=offset_basis;
	hash^=key;
	hash=hash*FNV_prime;
	return hash;
}
unsigned int jenkins_hash(int key)
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
	return hash;
}
int main()
{	int n,i,j,numarr[20],q,num,bitarr[50]={0},flag=0,falsecases=0;
	float probfalse;
	printf("Enter no. of elements to add: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{	printf("Enter value: ");
		scanf("%d",&numarr[i]);
		unsigned int x,y,z;
		x=murmurhash3_32(numarr[i]);
		y=fnv1(numarr[i]);
		z=jenkins_hash(numarr[i]);
		printf("Value After Murmurhash3: %u\n",x);
		printf("Value After FNV-1 Hash: %u\n",y);
		printf("Value After Jenkins Hash: %u\n",z);
		bitarr[hash1(numarr[i])]=1;
		bitarr[hash2(numarr[i])]=1;
		bitarr[hash3(numarr[i])]=1;
	}
	printf("Enter no. of queries: ");
	scanf("%d",&q);
	for(i=0;i<q;i++)
	{	printf("Enter value to check: ");
		scanf("%d",&num);
		if(bitarr[hash1(num)]==1 && bitarr[hash2(num)]==1 && bitarr[hash3(num)]==1)
		{	for(j=0;j<n;j++)
			if(num==numarr[j])
				flag=1;
			if(!flag)
				falsecases++;
			printf("Element in set\n");
			flag=0;	
		}
		else
			printf("Element not in set\n");
	}
	printf("NUMBER OF FLASE OUTPUTS: %d\n",falsecases);
	probfalse=(falsecases*100)/q;
	printf("PROBABILITY OF FLASE OUTPUTS: %.2f %\n",probfalse);
	return 0;
}
