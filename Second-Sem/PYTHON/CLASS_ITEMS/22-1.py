x=input()
#print (x).is_integer()	#outputs true/false value
#print 5.2 % 1.0              #valid
x=[1,2,3,4]
y=[3,4,5,6]
def common(x,y):
  r=[]
  for i in x:
    if i in y and i not in r:
      r.append(i)
  return r

print common(x,y)
print common('hello','hi') #valid - example of polymorphism
print 2 < 'hello'
print (1,2,3) < 'hello' #() creates a tuple - immutable
z=(1,2,3)
#z[0]=4	#gives an error as we can't change values of a tuple
a=[[1,2,3],[4,5,6],[7,8,9]]
b=[[1,2],[3,4],[5,6]]
c=[[]*len(b[0])]*len(a)
for i in range(len(a[0])):
  for j in range(len(b)):
    c[i][j]=0	
    for k in range(len(a)):
      c[i][j]+=a[i][k]*b[k][j]
print c
q=input('HOLD SCREEN')
