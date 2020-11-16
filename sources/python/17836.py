
import sys
from collections import deque
input = sys.stdin.readline


def isRange(y, x):
    if y >= 0 and y < n and x >= 0 and x < m:
        return True
    else:
        return False


def bfs(arr, y, x):
    visited = [[False] * m for _ in range(n)]
    q = deque()
    q.append((0, 0, 0))
    while q:
        cnt, cy, cx = q.popleft()
        visited[cy][cx] = True
        if cy == y-1 and cx == x-1:
            return cnt
        for i in range(4):
            ny = cy + dy[i]
            nx = cx + dx[i]
            if isRange(ny, nx) and not visited[ny][nx]:
                if arr[ny][nx] != 1:
                    visited[ny][nx] = True
                    q.append((cnt+1, ny, nx))
    return 1e9


n, m, t = map(int, input().split())
shiro = []
for _ in range(n):
    shiro.append(list(map(int, input().split())))

gy, gx, gcnt = -1, -1, 1e9
for i in range(n):
    for j in range(m):
        if shiro[i][j] == 2:
            gy = i+1
            gx = j+1
            break
    if gy != -1:
        break

dy = [-1, 1, 0, 0]
dx = [0, 0, -1, 1]
gcnt = bfs(shiro, gy, gx)
cnt = bfs(shiro, n, m)
ret = min(cnt, gcnt + n-gy + m-gx)
if ret > t:
    print("Fail")
else:
    print(ret)
