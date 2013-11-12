names=[]
n=[]
f1=open('Names','r')
names=f1.readlines()
f1.close()
for i in names:
     z=names.count(i)
     if z>1:
	  n.append(i)
	  while z!=0:
	       names.remove(i)
	       z=z-1

n.sort()
for i in n:
     print i,
