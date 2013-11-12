# if u want that ur class object becomes iterable ==>> u need to define an iterator and when u do print i it takes a# value from def next(self):




# CLASSES DO SUPPORT FUN. OVERRIDING MEANS THAT WE CAN CHANGE A FUNCTION IN A INHERITED CLASS ACC. TO OUR NEEDS
# IN A CLASS WHEN WE WRITE A FUNC. THE FIRST ARG. PASSED IS A POINTER TO THE CALLED OBJ. ONLY NAME NEED NOT BE SELF
# I THINK OBJECTS ARE SYNONYMS TO INSTANCES
# WHEN WE DO P1.SALARY=1000 AND SALARY IS NOT DEFINED IN THE CLASS IT IS CREATED ONLY FOR OUR INSTANCE P1

#OOP in Python
#Basic OOP concepts: encapsulation, polymrphism, inheritance
#encapsulation: bundle all methods and data into 1 class
#polymorphism: different forms of something (overloading)
#inheritance: one class using properties of another class

class person(object):	#writing (object) is optional. we write this when it does'nt inherit from anywhere
	def __init__(self,n='GAURAV'):	#init is a constructor
		self.name=n	#self is kind of pointer to the current object being called
	def setname(sel,n):
		sel.name=n
	def getname(self):
		return self.name
	def __iter__(self):	#need this if we want to use class in loops eg. for i in person:
		return self

#p1=person()	#will give error as it needs initial value
p1=person('Ram')
print p1.getname()
p2=person()
print p2.getname()
p1.setname('John')
print p1.getname()
p3=person()
p3.setname('SAURABH')
print p3.name
p3.name='amit'
print p3.name

#FIBONACCI CLASS
class fibs:
	def __init__(self):
		self.a=0
		self.b=1
	def next(self):		#this is inbuilt method to call next object in loop
		self.a, self.b = self.b, self.a+self.b
		return self.a
	def __iter__(self):
		return self

f1=fibs()

print "FIBONACCI SERIES"
x=input('Enter Limit: ')
for i in f1:
     print i  #means print i.next
     if (i>x):
	     break
	
#__x__ functions are defined to create,initialise new objects

#NUMBER CLASS
class number:
	def __init__(self,start):
		self.data=start
	def __sub__(self,other):	#we can now use this for subtracting class
		res=self.data-other
		return number(res)
	def __add__(self,other):	#we can now use this for adding class
		res=self.data+other
		return number(res)
	def __mul__(self,other):	#we can now use this for multiplying class
		res=self.data*other
		return number(res)

x=number(5)
print 'X: %d' %(x.data)
y=x-2
a=x+2
z=x*2		#now y becomes a class of type number with value 2 less than that of object
print 'Y: %d' %(y.data)
print 'Z: %d' %(z.data)
print 'A: %d' %(a.data)

#PRACTICE AND IT IS VERY IMP THAT U UNDERSTAND THAT IT IS NOT MANDATORY TO CALL THE FUN. OF SUPERCLASS IF U DO NOT C#ALL THEM EXPLICITLY THAT IS A CASE OF FUN OVRRIDING AND THOSE NAMES WILL NOT BE INI. FOR SUBCLASS
class gaurav_mishra(person):	
	def __init__(self,n,prop="intelligent"):   #n which is object of person also needs to be passed in constructor of derived class
		person.__init__(self,n)	#base class constructor is called explicitly
		self.prop=prop
		self.fool=0
	def getprop(self):
		return self.name+' is '+self.prop
	def setprop(self,new):
		self.prop=new
	def isfool(self):
		return self.fool+1
	def setfool(self,n):
		self.fool=n

gm=gaurav_mishra("Gaurav")
print gm.getprop()
if(gm.isfool()):
	print "Gaurav is gaurav"
else:
	print "Gaurav"
