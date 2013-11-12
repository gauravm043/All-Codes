class link_list:
     def __init__(self,data):
	  self.data=data
	  self.nex=None
     
     def insert_begin(head,node):
	  node.nex=head
	  return node
     
     def insert_end(head,node):
	  if head.nex:
	       head.nex.insert_end(node)
	  else:
	       head.nex=node

     def delete(head,prev,n):
	  head=head.nex
	  if prev.data==n:
	       prev.nex=head.nex
	  else:
	       head.nex.delete(head,n)
	       

     def print_it(head):
	  if head:
	       print '-->> '+str(head.data),
	  if head.nex:
	       head.nex.print_it()


head=link_list(3)

for i in range(100):
     x=raw_input()
     if x=='Q':
	  break
     if x=='B':
	  n=input()
	  head=head.insert_begin(link_list(n))
     if x=='P':
	  head.print_it()
	  print ' '
     if x=='E':
	  n=input()
	  head.insert_end(link_list(n))
     if x=='D':
	  n=input()
	  head.delete(head,n)
     

