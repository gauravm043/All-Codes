arr=[]

def triplet(n):
     num=0
     for z in range(100000):
	  for y in range(z):
	       for x in range(y):
		    if(x<=y):
			 if (x*x+y*y)==(z*z):
			   l=[]
			   l.append(x+y)
			   l.append(x)
			   l.append(y)
			   l.append(z)
			   arr.append(l)
			   num=num+1
			   if num==n:
			     return



n=input()
triplet(n)

arr.sort()
for i in range(len(arr)):
     print arr[i][1],
     print arr[i][2],
     print arr[i][3]

