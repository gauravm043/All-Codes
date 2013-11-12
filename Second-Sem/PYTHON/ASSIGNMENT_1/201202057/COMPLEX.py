import math
w=""
a=raw_input()
a=a.split(",")
for m in a:
     x=[]
     x.append(m.split("i"))
     q=x[0][0][0:-1]
     real=float(q)
     img=float(x[0][1])
     w=w+(str('%0.2f'%math.sqrt(real*real+img*img)))
     w=w+","
print w[:-1]
