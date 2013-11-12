import os
import sys
os.chdir('/home/gaurav')
sys.stdout=open('hello','w')
os.system('ls')
