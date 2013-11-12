import re
import os
import sys
#p="cd "
#t=raw_input("ENTER A URL: ")
#x="wget http://"
#x=x+t
#x=x+" -O file.html"
#os.system(x)
f=open('file.html','r')
l=f.readlines()
st=""
for i in l:
     st=st+str(i)

m=re.findall("<div.*>.+</div>",st)
#print m
p=""
x=[]
for i in m:
     p=re.sub("<a.*/a>|</div>|<div>","",i)
     print p
     x.append(p)
#print x
