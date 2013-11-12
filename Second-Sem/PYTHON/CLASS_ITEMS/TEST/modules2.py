# IN PYTHON THE FUNCTIONS OF GREAT IMPORTANCE ARE:
#1-	OS.SYSTEM
#2-	OS.CHDIR
#3-	OS.LISTDIR(PATH)
#4-	OS.PATH.ISFILE(PATH)
#5-	OS.PATH.ISDIR(PATH)		Are evaluating to True or not
#6-	OS.PATH.EXISTS(PATH)
#7-	OS.PATH.ABSPATH(PATH) 	Gives us what is the abs path of $path
#8-	OS.PATH.BASENAME(PATH)
#9-	OS.PATH.DIRNAME(PATH)		Gives us the Dir name of a path given

from re import *
import string
greeting='hello gaurav'
print greeting.upper()
greeting=string.capwords(greeting)
print greeting

for i in open('/etc/passwd'):
     	x = split(':',i)
	print x[0], x[2] 



import os
x=raw_input()
l=os.listdir(x)
print l
for i in l:
     i=x+'/'+i
     if(os.path.isfile(i)==True):
	  print i
