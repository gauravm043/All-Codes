#Handling of errors:
try:
     1/1
     raise ZeroDivisionError                    #It will raise the exceptions

except ZeroDivisionError:			#Will execute if error occurs
     print "You are dividing by 0"

class lst:
     def __init__(self):
	  self.vals=[1,1,2,3,4,6]
	  self.cur=0
	  self.tot=len(self.vals)
     def next(self):
	  if(self.cur<self.tot):
	       self.cur+=1
	       return self.vals[self.cur-1]
	  else:
	       raise StopIteration
     def __iter__(self):
	  return self

a=lst()
for i in a:				#When we do this it does not mean 'a' should have a next fun but it should hv a iter fn
     					#but the obj returned by iter mst be iterable
     print i



#for i in a 
#returns self ---->>> obj by calling iter only once and the obj must have a next fun 
#then obj->next is called always
