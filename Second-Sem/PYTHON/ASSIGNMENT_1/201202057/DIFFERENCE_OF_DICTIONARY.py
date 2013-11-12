t=input()
while t!=0:
     w=""
     q=""
     a=raw_input()
     b=raw_input()
     a1=a.split(",")
     b1=b.split(",")
     a=raw_input()
     b=raw_input()
     a2=a.split(",")
     b2=b.split(",")
     for i in range(len(a1)):
	  if a1[i] not in a2:
	       w=w+a1[i]+","
   
     for i in range(len(a1)):
	  if a1[i] not in a2:
	       q=q+b1[i]+","
     t=t-1
     print w[:-1]
     print q[:-1]
