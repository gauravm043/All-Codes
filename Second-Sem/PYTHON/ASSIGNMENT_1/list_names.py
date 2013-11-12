name=[]
n=input()
while n!=0:
     n1=raw_input()
     name.append(n1)
     n=n-1

src=raw_input('ENTER A NAME TO SEARCH: ')
print 'POSSIBLE SUGGESTIONS ARE: '
for i in name:
     if i[0]==src[0] and i[1]==src[1] and i[2]==src[2]:
	  print i
