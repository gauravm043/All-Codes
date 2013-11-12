names=[]
f1=open('NAMES','r')
names=f1.readlines()
f1.close()

for i in names:
     z=names.count(i)
     while z!=1:
	  names.remove(i)
	  z=z-1

names.sort()
for i in names:
     print i,
