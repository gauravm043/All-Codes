#	THE MAP FUN TAKES ARGUMENT AS AN IERABLE OB ONLY





def add(x,y):
     return x+y

def cube(n):
     return n**3

m=map(add,[8,9],[1,2])
print m

m=map(cube,[9])
print m





#	FILTER FUNCTION A LIST ACCORDING TO A GIVEN FILTER


def even(n):
     if(n%2==0):
	  return 1
     else:
	  return 0

m=filter(even,[7,8,9,10])
print m



#	REDUCE FUN TAKES ONLY ONE ITERABLE OB AND IT CALLS TAKING ONE AT A TIME AND RETURNS A REDUCED VALUE 								IF ARGU. ARE LESS DEFAULT=0
m=reduce(add,[1])
print m




#	LAMBDA

m=reduce(lambda x,y: x-y,[1,2,3])
print m


freshfruit = [' ban  ana', ' apple ', 'grape ']
j=[x.strip() for x in freshfruit]
print j
vec=[1,2,3,4]
m=[(x, x**2) for x in vec]
print m

