import math
def prime(n):
     if n==1:
	  return 0
     else:
	  for i in range(2,n):
	       if n%i==0:
		    return 0
     return 1


n=input('ENTER A NUMBER: ')
ans=prime(n)
if ans==1:
     print 'PRIME'
else:
     print 'NOT PRIME'
