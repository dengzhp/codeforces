import sys
import heapq

n, m = sys.stdin.readline().split()
n = int(n)
m = int(m)

seats = [int(x) for x in sys.stdin.readline().split()]

minheap = []
maxheap = []
for i in seats:
    heapq.heappush(minheap, i)
    heapq.heappush(maxheap, -i)


mincost = 0
maxcost = 0
for i in range(n):
    c = heapq.heappop(minheap)
    if c > 1:
        heapq.heappush(minheap, c-1)
    mincost += c

    c = heapq.heappop(maxheap)
    if c < -1:
        heapq.heappush(maxheap, c+1)
    maxcost -= c

print maxcost, mincost
