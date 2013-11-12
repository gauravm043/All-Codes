def average(l):
     sum=0
     for i in l:
	  sum+=i
     return float(sum)/len(l)



l=[]
l=input('ENTER AN ARRAY:')
ans=average(l)
print ans
