import sys
from collections import deque
input = sys.stdin.readline

sys.setrecursionlimit(10**9)


def dfs(arr, visited, q, cx):
    if q[0] == arr[cx]:
        return True
    nx = arr[cx]
    if not visited[nx]:
        q.append(nx)
        visited[nx] = True
        return dfs(arr, visited, q, nx)
    else:
        return False


n = int(input())
arr = [0]
visited = [False] * (n+1)
for i in range(1, n+1):
    arr.append(int(input()))

for i in range(1, n+1):
    q = deque()
    if not visited[i]:
        visited[i] = True
        q.append(i)
        ret = dfs(arr, visited, q, i)
        if not ret:
            while q:
                p = q.popleft()
                visited[p] = False

cnt = 0
ret = []
for i in range(len(visited)):
    if visited[i]:
        cnt += 1
        ret.append(i)

print(cnt)
for r in ret:
    print(r)
