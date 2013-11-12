def average(C):
     avg=0
     for i in range(len(C)):
	  avg=avg+C[i]
     return int(avg/len(C))
     
t=input()
num=1.0

while t!=0:
   A=[]
   B=[]
   C=[]
   num=raw_input()
   A.append(num)
   B=A[0].split(" ")
   for i in range(len(B)):
	C.append(int(B[i]))
   av=average(C)
   print av
   t=t-1
