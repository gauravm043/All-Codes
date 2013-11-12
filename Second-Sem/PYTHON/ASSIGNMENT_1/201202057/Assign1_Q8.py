def triplet():
     for z in range(101):
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

arr=[]
triplet()
arr.sort()
for i in range(len(arr)):
     print arr[i][1],
     print arr[i][2],
     print arr[i][3]

