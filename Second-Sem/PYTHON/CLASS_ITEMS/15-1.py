fo=open("sample","r")	#r-read w-write a-append
#text=fo.read()
#print text - file pointer goes to the end in reading the file
#stores all content of file as one string
lines=fo.readlines()
#lines then contains all lines as different strings in a list
#print lines
for i in lines:
  print i,	#writng 'for i in lines' makes i a string
fo.seek(0) #this will take us to the nth byte in file

#other commands
a='xyz pqrst abcd'
l=a.split(' ') #l contains list of strings splitted with spaces of orig. string
print l
z=sorted(l,key=lambda w:len(w))  #lambda-shorthand way to define func.
#this function returns length into variable key and that is used as basis for sorting
print z
b={"hello":1,"bye":20,"world":2}
print b
print max(b.keys(),key=lambda w:b[w])
c=sorted(b.keys(),key=lambda w: b[w])
print c
t=input()
