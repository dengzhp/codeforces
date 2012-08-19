import sys

n = input()
pl = []
for i in range(n):
    v = sys.stdin.readline().split()
    pl.append(v)

visited = [0] * n

result = 0

def dfs(i):
    if visited[i]:
        return
    visited[i] = 1
    for j in range(n):
        if j != i and (pl[i][0] == pl[j][0] or pl[i][1] == pl[j][1]):
            dfs(j)

for i in range(n):
    if not visited[i]:
        result += 1
    dfs(i)

print result - 1
