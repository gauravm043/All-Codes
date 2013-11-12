def sort(C):
     for i in range(len(C)):
	  for j in range(len(C)-i):	 
	       if j+1<len(C) and C[j]>C[j+1]:
	          tmp=C[j]
		  C[j]=C[j+1]
		  C[j+1]=tmp

t=input()
while t!=0:
     t=t-1
     A=[]
     C=[]
     m=raw_input()
     A=m.split(" ")
     for i in A:
      C.append(int(i))
     sort(C)
     for i in range(len(C)):
	  print C[i],
     print ""

