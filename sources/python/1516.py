import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]
deg = [0 for _ in range(n+1)]
times = [0 for _ in range(n+1)]
for i in range(1, n+1):
    inp = list(map(int, input().split()))
    times[i] = inp[0]
    for j in inp[1:]:
        if j == -1:
            break
        graph[j].append(i)
        deg[i] += 1

q = deque()
for i in range(1, n+1):
    if deg[i] == 0:
        q.append(i)

ret = []
save = [i for i in times]
while q:
    cx = q.popleft()
    ret.append(times[cx])
    for i in range(len(graph[cx])):
        nx = graph[cx][i]
        deg[nx] -= 1
        save[nx] = max(save[nx], save[cx]+times[nx])
        if deg[nx] == 0:
            q.append(nx)
for s in save[1:]:
    print(s)
