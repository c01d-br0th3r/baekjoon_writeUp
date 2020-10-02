import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
q = deque()
tomato = []
d = [[-1, 0], [1, 0], [0, -1], [0, 1]]
for i in range(m):
	tomato.append(list(map(int, input().split())))
	for j in range(n):
		if tomato[i][j] == 1:
			q.append([i, j, 0])

def isRange(cy, cx):
	if cy >= 0 and cy < m and cx >= 0 and cx < n:
		return True
	else:
		return False

def bfs():
	while len(q):
		cy, cx, cnt = q.popleft()
		for i in range(0, 4):
			ny = cy + d[i][0]
			nx = cx + d[i][1]
			if isRange(ny, nx) and tomato[ny][nx] == 0:	
				q.append((ny, nx, cnt+1))
				tomato[ny][nx] = tomato[cy][cx] + 1
	ret = -1
	for i in range(0, m):
		for j in range(0, n):
			if tomato[i][j] == 0:
				return -1
			if tomato[i][j] > ret:
				ret = tomato[i][j]
	return ret-1

print(bfs())


