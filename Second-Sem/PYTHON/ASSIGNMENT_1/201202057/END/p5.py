def add(file_name):
     name=raw_input('Enter your Name:\n')
     num=input('Enter your Number:\n')
     f1=open(file_name,'a')
     f1.write(name)
     f1.write(':')
     f1.write(str(num))
     f1.write('\n')
     f1.close()


def delete(file_name):
     name=raw_input('Enter your Name:\n')
     f1=open(file_name,'r')
     d={}
     lines=f1.readlines()
     f1.close()
     for i in lines:
	  if name!=i.split(':')[0]:
	       d[i.split(':')[0]]=i.split(':')[1]
     
     print d
     f1=open(file_name,'w')
     for i in d:
	  f1.write(i)
	  f1.write(':')
	  f1.write(d[i])
     f1.close()

file_name=raw_input('ENTER THE NAME OF THE FILE: \n') 
n=1
d={}

while n!=3:
     print 'Enter your Preference:\n'
     print '1: Add'
     print '2: Delete'
     print '3: Quit'
     n=input()
     if n==1:
	  add(file_name)
     if n==2:
	  delete(file_name)
