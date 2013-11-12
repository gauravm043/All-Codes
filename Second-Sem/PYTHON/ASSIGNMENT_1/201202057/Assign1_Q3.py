def intersection(a,b):
     for i in range(len(a)):
	  for j in range(len(b)):
	       if(a[i]==b[j]):
		    print a[i],
     print ""
     return 0
		  
		    
	       
t=input()
while t!=0:
     t=t-1
     a=[]
     b=[]
     mode=raw_input()
     if(mode=='LIST'):
       m=raw_input()
       n=raw_input()
       a=(m.split(" "))
       b=(n.split(" "))
       K=intersection(a,b)
       continue
     if(mode=='STRING'):
       m=raw_input()
       n=raw_input()
       for i in m:
	    if i in n:
		 a.append(i)
       print "".join(a)
