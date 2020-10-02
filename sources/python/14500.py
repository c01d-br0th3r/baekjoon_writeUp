import sys
input = sys.stdin.readline

arr = []
ret = -1
dy = [1, -1, 0, 0]
dx = [0, 0, -1, 1]
N, M = map(int, input().split())
for i in range(N):
	arr.append(list(map(int, input().split())))
visited = [[False] * M for _ in range(N)]
tmp = 0

def isRange(y, x):
	if y >= 0 and y < N and x >= 0 and x < M:
		return True
	else:
		return False

def dfs(cy, cx, cnt, total):
	global ret
	tmp = total + arr[cy][cx]
	visited[cy][cx] = True
	if cnt == 3:
		if tmp > ret:
			ret = tmp
		return 0
	for i in range(4):
		ny = cy + dy[i]
		nx = cx + dx[i]
		if isRange(ny, nx) and not visited[ny][nx]:
			visited[ny][nx] = True
			dfs(ny, nx, cnt+1, tmp)
			visited[ny][nx] = False
	visited[cy][cx] = False

def middle(cy, cx):
	global ret

	if cx+2 < M and cy-1 >= 0:
		total = arr[cy][cx] + arr[cy][cx+1] + arr[cy][cx+2] + arr[cy-1][cx+1]
		if total > ret:
			ret = total
	if cx+2 < M and cy+1 < N:
		total = arr[cy][cx] + arr[cy][cx+1] + arr[cy][cx+2] + arr[cy+1][cx+1]
		if total > ret:
			ret = total
	if cy+2 < N and cx+1 < M:
		total = arr[cy][cx] + arr[cy+1][cx] + arr[cy+2][cx] + arr[cy+1][cx+1]
		if total > ret:
			ret = total
	if cy+2 < N and cx-1 >= 0:
		total = arr[cy][cx] + arr[cy+1][cx] + arr[cy+2][cx] + arr[cy+1][cx-1]
		if total > ret:
			ret = total

for i in range(N):
	for j in range(M):
		dfs(i, j, 0, 0)
		middle(i, j)

print(ret)
