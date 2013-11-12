l=[]
import re
pattern=r"(abc)\1"
text="abcabc"
l=re.findall(pattern,text)
print l
