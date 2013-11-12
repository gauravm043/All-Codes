from math import *
t=input()
while (t!=0):
     t=t-1
     n=input()
     x=raw_input()
     if (n%2!=0):
	  print (2**(n-1))%1000000007
     else:
	  pro=factorial(n)/(factorial(n/2)**2)
	  ans=(((2**(n))-pro)/2)%1000000007
	  print ans  
