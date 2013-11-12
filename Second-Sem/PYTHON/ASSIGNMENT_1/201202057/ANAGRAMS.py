import itertools
t=input()
while t!=0:
     t=t-1
     l=[]
     a=raw_input()
     y=itertools.permutations(a)
     print y
     for k in y:
       if k not in l:
	  l.append(k)
     l.sort()
     
     for i in range(len(l)):
       w=""
       for j in range(len(a)):
	  w=w+l[i][j]
       print w
