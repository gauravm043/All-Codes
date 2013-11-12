import re
message=""
encoded=""
pattern=".*<.*3"
n=input()
while(n!=0):
    n=n-1
    x=raw_input();
    for i in range(len(x)):
        pattern+=x[i]
        pattern+=".*"
    pattern+=".*<.*3"
#print pattern
encoded=raw_input()
m=re.search(pattern,encoded)
if m:
    print 'yes'
else:
    print 'no'
