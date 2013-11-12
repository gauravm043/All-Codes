#All the class variables are common to all instances but this is not for instance variables
#and the init fun creates instance variables  but they are available to all instances but are local to every instance
#since a and b are not self.a etc





class A:
     """A CLASS"""
     a = 1		#These are called CLASS variables
     b = 2
     def __init__(self):
	  self.x=1
	  self.y=2	#The init constructor is called and these instance vari are created
	  print 'CONSTRUCTOR for A called'

     def p(self):
	  print self.a,self.b,self.x



print A.__doc__		#Documentations
c=A()			#The instance of a class is an object
c.p()			#Self is like an obj passed to itself
			#It maens a.p()=A.p(a) ie: a is an obj and it is passed when p fun is called

c.x = 100
print c.x		#This variable is local to this instance only and is known as INSTANCE VARIABLE


#----------------------------------------------------------------------------------------------------------------------------#

#In order to update the whole CLASS VARIABLES DO

A.a=20
c.p()




print '\n\nQUE:1\n\n'


#Operator overloading:
#helps us to add etc to an object eg: A=B+C

class com:
     __a=1
     def __init__(self,a=2,b=3):
	  self.real=a
	  self.img=b
     def __add__(self,other):
	  q=self.real+other.real
	  w=self.img+other.img
	  return com(q,w)
     def __sub__(self,other):
	  q=self.real-other.real
	  w=self.img-other.img
	  return com(q,w)
     def p(self):
	  print self.real
	  print self.img
     def __str__(self):						#This is the overloading of print function
	  return str(self.real)+'+('+str(self.img)+')' + 'i'



Q=com(9,8)
R=com(1,15)
Ans=Q+R
print Ans
Ans=Q-R
print Ans
#print Q.a


#------------------------------------------------------------------------------------------------------------------------------#

#3}-->>
#To define a private variable do __a=1
#They are not accessile from outside






						#INHERITANCE:-

class Emp:
     def __init__(self,name,age):
	  self.name=name
	  self.age=age
     def incage(self):
	  self.age+=1

class Manager(Emp):
     def __init__(self,name,age,salary):
	  Emp.__init__(self,name,age)
	  self.salary=salary
     def p(self):
	  print self.name,self.age,self.salary
     def incage(self):
	  self.age+=100

m=Manager("abc",40,40000)
m.p()					

#ACTUALLY WHEN A FUN IS CALLED FOR AN OBJECT IT WILL SEARCH FOR A FUN IN INSTANCE AND THEN IN ITS CLASS AND THEN IN ITS SUPER CLASSES
