class Person(object):
     def setName(self, name):
	  self.name = name
     def getName(self):
	  return self.name
     def greet(self):
	  print "Hello, world! I'm %s" % self.name


p1=Person()
p1.setName('GAURAV')
print p1.greet()
