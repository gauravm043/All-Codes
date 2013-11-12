def components(i,j,ARR):
     if (ARR[i][j]==0 or ARR[i][j]==10):
	  return
     else:
          ARR[i][j]=10
          if (j+1<n):
	       components(i,j+1,ARR)
	  if (j-1>=0):
	       components(i,j-1,ARR)
	  if (i+1<n):
	       components(i+1,j,ARR)
	  if (i-1>=0):
	       components(i-1,j,ARR)
     return
	   
ARR=[]
n=input()
for i in range(n):
     inp=[]
     for j in range(n):
	  num=input()
	  inp.append(num)
     ARR.append(inp)

print 'YOUR ARRAY IS: '
print ARR

ans=0

for i in range(n):
     for j in range(n):
	  if (ARR[i][j]==1):
	       components(i,j,ARR)
	       ans=ans+1

print 'THE NUMBER OF COMPONENTS IN THE GRAPH ARE: '+'%d'%ans
