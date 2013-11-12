d={}
d['jan']=100 #here key is 'jan' and  value is 100
#values can also be lists
d['feb']=200 #use as a regular array
print 'original d=',d
#keys must be immutable (non-modifiable) : strings,numbers etc.
#lists are unhashable as they are mutable, so cannot be used as keys
k=d.keys()
print 'array of keys:',k
k.sort()
print 'sorted keys:',k #keys are sorted now, so if we want to traverse with keys in sorted order, we can traverse k and take values
d2={}
d2=d #we have created d2 as an alias of d, so any change in d2 is reflected in d
d2['jan']=50
print 'd2=',d2
print 'd=',d
x=d2['jan']
print x
def f():
  return 1
d2['mar']=f()
print 'new d2:',d2
