#Function defined outside the class
def f1(self, x, y):
     return min(x, x+y)

class C:
     f = f1
     def g(self):
	return 'hello world'
     h = g

obj1=C()
print obj1.f(1,2)
print obj1.g()
print obj1.h()


# THE PRIME CLASS

class prime:
     def __init__(self):
	  self.data=2
     def next(self):
	  while 1:
	       self.data+=1
	       for i in range(2,self.data):
		    if self.data%i==0:
			 break
	       else:
		    return (self.data)
		    

     def __iter__(self):
	  return self

     def __str__(self):
	  return str(self.data)

P=prime()
n=1
for i in P:
     n+=1
     if(n==10000000):
       print i
       break
