class bst:
	"""binary search tree"""
	def __init__(self,data):
		self.data=data
		self.l=0
		self.r=0
		self.left=None
		self.right=None

	def insert(root,node):
		if root==None:
			root=node
		elif root.data > node.data:
		     	if root.left==None:
			     	root.l+=1
				root.left=node
			else:
			     	root.l+=1
				root.left.insert(node)
		else:
		     	if root.right==None:
			     	root.r+=1
				root.right=node
			else:
			     	root.r+=1
				root.right.insert(node)
	def inorder(root):
		if root:
		     if root.left:
				root.left.inorder()
		     print str(root.data)+'--> left ( '+str(root.l)+' )  and  right (   '+str(root.r)+' ) '
	             if root.right:
				root.right.inorder()

	def k_minimum(root,posi,k):
	     	if root:
	             posi=posi+root.l+1
		     if posi==k:
			  print 'Required Minimum: '+str(root.data)
		     elif posi<k:
			  if root.right:
			       root.right.k_minimum(posi,k)
			  else:
			       print 'NOT THERE'
		     elif posi>k:
			  if root.left:
			       posi=posi-root.l-1
			       root.left.k_minimum(posi,k)
			  else:
			       print 'NOT FOUND'
	        else:
		      print 'NOT FOUND'



	def search(root,value):
		if root==None:
			print 'NOT FOUND'
		elif root.data<value:
			if root.right:
				root.right.search(value)
			else:
				print 'NOT FOUND'

		elif root.data>value:
			if root.left:
				root.left.search(value)
			else:
				print 'NOT FOUND'
		else:
			print 'FOUND'

root=bst(3)
root.insert(bst(5))
root.insert(bst(1))
root.insert(bst(10))
root.insert(bst(-10))
root.insert(bst(120))
root.insert(bst(1320))
root.inorder()

print

for i in range(10):
	b=input()
	root.k_minimum(0,b)

print

for i in range(10):
	b=input()
	root.search(b)
print 'END!!'
