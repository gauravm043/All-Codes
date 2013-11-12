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

class rational(object):
     def __init__(self,data1,data2):
	  self.p=data1
	  self.q=data2

class whole(rational):
     def __init__(self,data1):
	  rational.__init__(self,data1,1)

class natural(whole):
     def __init__(self,data1):
	  if(data1==0):
	       print 'asasa'
	  else:
	       whole.__init__(self,data1)
print 'hello'
x=rational(2,3)
print x.p,x.q
y=whole(4)
print y.p,y.q

z=natural(9)
print z.p,z.q

class prime(natural):
     def __init__(self,data):
	  natural.__init__(self,data)
     def next(self):
	  while 1:
	       self.p+=1
	       for i in range(2,self.p):
		    if self.p%i==0:
			 break
	       return (self.p)
		    

     def __iter__(self):
	  return self

     def __str__(self):
	  return str(self.p)

P=prime(1)
n=0
for i in P:
     n+=1
     if(n==20):
       print i
       break
