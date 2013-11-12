n=input('ENTER N: ')
for i in range(n):
   print ' '*(n-i-1) + '*'*(2*i+1)
for i in range(n):
   print ' '*(i) + '*'*(2*(n-i)-1)

