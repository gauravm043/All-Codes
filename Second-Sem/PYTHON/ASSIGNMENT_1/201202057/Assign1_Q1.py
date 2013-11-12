def prime(n):
     if n==1:
	  return 0
     for i in range(2,n-1):
	  if(n%i==0):
	       return 0
     return 1

t=input()
while t!=0:
  num=input()
  a=prime(num)
  if(a==1):
     print 'YES'
  else:
     print 'NO'
  t=t-1
