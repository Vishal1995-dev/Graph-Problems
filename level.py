from queue import Queue
from collections import defaultdict
n=int(input())

a=defaultdict(list)
v=[0]*(n+1)
l=[0]*(n+1)

for i in range(n-1):
	x,y=map(int,input().split())
	a[x].append(y)
	a[y].append(x)

level=int(input())

q=Queue(maxsize=100)
q.put(1)
v[1]=1
l[1]=1

while(not q.empty()):
	p=q.get()
	for i in a[p]:
		if(v[i]==0):
			l[i]=l[p]+1
			q.put(i)
			v[i]=1
			
print(l.count(level))
