#SEARCHING

def search():
     words=[]
     f1=open('PHONE_DIRECTORY','r')
     lines=f1.readlines()
     for i in lines:
	  words.append(i.split(" "))
     name=raw_input('ENTER NAME: ')
     for i in range(len(words)):
	  if words[i][0]==name:
	       print 'NUMBER OF '+ name + ' IS: ' + words[i][1]
	       break
     else:
	  print 'NO MATCH FOUND'
     f1.close()

#ADDING	

def add():
     name=raw_input('ENTER NAME: ')  
     num=input('ENTER NUMBER: ')
     f1=open('PHONE_DIRECTORY','a')
     f1.write(name)
     f1.write(" ")
     f1.write('%d'%num)
     f1.write("\n")
     f1.close()

#MODIFY

def modify():
     index=0
     lines=[]
     words=[]
     f1=open('PHONE_DIRECTORY','r')
     name=raw_input('ENTER NAME: ')
     num=input('ENTER NUMBER: ')
     lines=f1.readlines()
     for i in lines:
	  words.append(i.split(" "))
     for i in range(len(words)):
	  if words[i][0]==name:
	       index=i
	       break
     else:
	  print 'NO MATCH FOUND\n'
     f1.close()
     lines[index]=name+' %d\n'%num
     f1=open('PHONE_DIRECTORY','w')
     f1.writelines(lines)
     f1.close()

# VIEW ALL

def view():
     print "\n"
     words=[]
     lines=[]
     f1=open('PHONE_DIRECTORY','r')
     lines=f1.readlines()
     for i in lines:
	  words.append(i.split(" "))
     for i in range(len(words)):
	       print 'NUMBER OF '+ words[i][0] + ' IS: ' + words[i][1],


n=1
while n!=7:
  print "\n"
  print 'ENTER YOUR CHOICE:'
  print '1-SEARCH'
  print '2-ADD AN ENTRY'
  print '3-MODIFY NUMBER'
  print '4-VIEW ALL'
  print '5-SAVE TO A FILE'
  print '6-LOAD FROM A FILE'
  print '7-EXIT'
  n=input()
  if n==1:
     search()
  elif n==2:
     add()
  elif n==3:
     modify()
  elif n==4:
     view()
  elif n==5:
       print 'SAVED'
  elif n==6:
       print 'LOADED'
