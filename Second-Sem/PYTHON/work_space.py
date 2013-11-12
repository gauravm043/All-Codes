x=1
print '%d' %x
#we can use complex num too
a=input()
b=input()
c=complex(a,b)
print '%d' %c.real
print '%d' %c.imag
a=abs(c)     #print magnitude
a
print '%d' %a
print 'doesn\'t'


hello = "This is a rather long string containing\n\
several lines of text just as you would do in C.\n\
    Note that whitespace at the beginning of the line is\
 significant."

print hello
#NOW IN TRIPPLE QUOTES NO NEED TO DO \ WITH n

print """
Usage: thingy [OPTIONS]
     -h                        Display this usage message
     -H hostname               Hostname to connect to
"""


#+---+---+---+---+---+
# | H | e | l | p | A |
# +---+---+---+---+---+
# 0   1   2   3   4   5
#-5  -4  -3  -2  -1


s = 'supercalifragilisticexpialidocious'
len(s)




# Replace some items:
a[0:2] = [1, 12]
a
#[1, 12, 123, 1234]
# Remove some:
a[0:2] = []
a
#[123, 1234]
# Insert some:
a[1:1] = ['bletch', 'xyzzy']
#a
[123, 'bletch', 'xyzzy', 1234]
# Insert (a copy of) itself at the beginning
a[:0] = a
a
#[123, 'bletch', 'xyzzy', 1234, 123, 'bletch', 'xyzzy', 1234]
 # Clear the list: replace all items with an empty list
a[:] = []
a

a[2].append('xtra')

a, b = 0, 1

#IN ONE LINE
a, b = 0, 1
while b < 1000:
     print b,
     a, b = b, a+bi

