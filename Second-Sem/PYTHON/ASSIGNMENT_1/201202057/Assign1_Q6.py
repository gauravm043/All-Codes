import string
name=raw_input()
inp=[]
f1=open(name,'r')
inp=f1.readlines()
f1.close()
names=[]
for i in inp:
     names.append(i.split("\n"))


# FOR REMOVING NULL VALUES

for i in range(len(names)):
     names[i].remove('')


# SEARCHING
C=string.capitalize

n=input()
while n!=0:
     ans=0
     n=n-1
     listed=[]
     inp=raw_input()
     print inp,
     for i in names:
	  if (C(inp[0])==C(i[0][0]) and C(inp[1])==C(i[0][1]) and C(inp[2])==C(i[0][2])):
	       ans=ans+1
	       listed.append(i[0])
     print ' MATCHES: ' + '%d'%ans
     for l in listed:
	  print l
     print ""
