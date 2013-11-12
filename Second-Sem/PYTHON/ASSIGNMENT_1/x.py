f=open('COLOR','w')
c=""
d={}
n=3
while n!=0:
     n=n-1
     na=raw_input()
     x=input()
     d[na]=x

for i in d:
     c=str(d[i])
     f.write(i)
     f.write(" ")
     f.write(c)
     f.write("\n")

f.close()

import os
print "OUTPUT--->\n"
os.system("vim COLOR")
