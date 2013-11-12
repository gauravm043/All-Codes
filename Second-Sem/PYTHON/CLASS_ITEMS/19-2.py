#Regular expressions - find patterns in a string
import re	#module for regular expressions
text="xyz pqr nishit"
#re.search(pattern,string) & pattern - any char. except \n
m=re.search("xyz",text)	#Finds first occurence of the pattern
print m
print m.group()
z="blf lfgf blf abcX asds bl blf"
m=re.search("...X",z)
print m.group()
m=re.search(".Y",z)	#when it doesnt find anything, it returns null
print m
#NOTE
# . : any single char.
# ? : 0 or 1 repititions eg. a?
# * : 0 or more repititions
# + : 1 or more repititions
# \w: alphanumeric & _ char.
# \s: white space char.
# \d:digit

text="bla bla aabc@xyz.com bla bla"	#here pattern is "\w+@\w+.com"
m=re.search("\w+@\w+.com",text)
if m:
	print m.group()
else:
	print "NOT FOUND!"
te="asd@asd.com asdsad@asdasd.com bla@xyz.com"
emailids=re.findall("\w+@\w+.com",te)	#finds all occurences of the pattern we give
print emailids

pattern="[abc]pqr"	# anything we put in bracket means that any 1 ofthose chars. can be present
#at that position of the string
s="ddf cpqr as"
m=re.search(pattern,s)
print m.group()
tex="udyan@abc.com udyan hello abc@c.com"
m=re.findall("[.\w]+@[\w?]+.com",tex)
print m

#Ques: find date pattern : dd/mm/yyyy or yy
p1="\d\d/\d\d/\d\d\d\d|\d\d/\d\d/\d\d"	#if it was 2,3,4 do: \d{m,n} (m to n inclusive repititions)
string="as 11/12/98 dfdf 12/10/1997 as"
x=re.findall(p1,string)
print x

pattern="[a]+|[b]+"
m=re.findall(pattern,"aaa bbb")
print m

t="my name is xyz xyz xyz"
t.replace("xyz","pqr")
print t

s="aaa aaaaa asdfasdf asdf sdfasdf    asdf"	#substitute: re.sub(pattern,newpattern,string)
a=re.sub("\w+","x",s)
print a
z="abc bca acb"
c=re.sub("abc","pqr",z)
print c

q="abc@xyz.com udyank@gmail.com"
pat="(\w+)@(\w+).com"
m=re.search(pat,q)
print m.group(1)
print m.group(2)
m=re.findall(pat,q)
print m

string="as 11/12/98 dfdf 12/10/1997 AS"
l=re.split("/",string)
print l
dl="!|,|x"
st="helo! my, namex is udyan, bye!"
l=re.split(dl,st)
print l

dl=re.compile("!|,|x")	#now dl is the pattern. all commands we execute with dl will be using this as pattern
print dl.split(st)
