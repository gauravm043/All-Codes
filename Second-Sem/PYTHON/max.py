def sort(A):
   max=A[0]
   for i in range(len(A)):
      if(A[i]>max):
         max=A[i]

   return(max)

A=[]
A=input('ENTER ARRAY: ')
max=sort(A)
print '%d' %max
