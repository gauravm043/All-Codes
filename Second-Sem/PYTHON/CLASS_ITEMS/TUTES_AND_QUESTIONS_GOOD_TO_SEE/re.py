#. : any char except a new line char
#? : 0 or 1 rep
# * :0 or more rep
#+ :1 or more rep
#\w :alphanumeric and _ character
#\s : whie space chatacter
# [abcd] any one will match the characters will be treated as it is not as re if any
# \d will match any numeric digit
#when we put  a (   ) on anywhere those groups are automatically created


#re.search will return an object
#re.findall will return a list of found items


#re.sub replaces patern1 with pattern 2 in a text
#returns string think so





import re
text="xyz nishith"
m=re.search("xyz",text)
print m.group()


text="blah blah abc@xyz.com blah blah"
m=re.search("\w+@\w+.com",text)
if m:
 print m.group()
else:
 print "NOT FOUND"


text="gaurav@abc.com gaurav hello abc@c.com"
m=re.findall("\w+@\w+.com",text)
print m


text="gau.ra.v@abc.com gaurav hello abc@c.com"
m=re.findall("[.\w]+@[\w?]+.com",text)
print m

m=[]
text="gaurav@a?b9c?.com gaurav hello abc@c.com"
m=re.findall("[.\w]+@[.\w?]+.com",text)
print m


pattern="\d\d/\d\d/\d\d\d\d|\d\d/\d\d/\d\d"
date="12/12/1996 11/34/90"
m=re.findall(pattern,date)
print m




pattern="[a]+|[b]+"
m=re.findall(pattern,"aaa bbb")
print m


text="abc abc bca"
m=re.sub("abc","pqr",text)
print m
print text


text="aaaaaaaaa lakjlkjalkjlkjlkj lkjlsjflkjsldkjf 0890980980980"
m=re.sub("\w+",".",text)
print m



text="gaurav@mishra.com me@hello.com"
pattern="(\w+)@(\w+).com"
m=re.search(pattern,text)
print m.group(2)

text="abc!xaz,asdfasdf;"
dl="!|,|;"
m=re.split(dl,text)                                              #  WILL RETURN A STRING  
print m



#    	RE.COMPILE 
#	IT WILL CREATE AN ALIAS FOR ALL ITS FUN. AND WILL ASSIGN A PATTERN TO IT WILL SEARCH IT ON ANY TEXT U GIVE

dl=re.compile("!|;")
m=dl.split(text)
print m


