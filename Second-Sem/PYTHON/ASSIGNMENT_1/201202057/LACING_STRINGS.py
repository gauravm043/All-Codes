t=input()
while t!=0:
     j=0
     x=""
     a=raw_input()
     b=raw_input()
     i,f1=0,0
     j,f2=0,0
     while 1:
	  if i in range(len(a)):
	       x=x+a[i]
	       i=i+1
	  else:
	       f1=1
	  if j in range(len(b)):
	       x=x+b[j]
	       j=j+1
	  else:
	       f2=1
	  
	  if f1==1 and f2==1:
	       break
     print x
     t=t-1
