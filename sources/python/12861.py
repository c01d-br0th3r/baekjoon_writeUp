A, B, N, M = map(int, input().split())
maxNum = 100001
visited = [False] * maxNum
q = []
ret = 0
q.append([N, 0])
def isRange(cx):
	if cx >= 0 and cx < maxNum:
		return 1
	else:
		return 0

while len(q):
	cx, cnt = q.pop(0)
	visited[cx] = True
	if cx == M:
		ret = cnt
		break
	for i in [cx+1, cx-1, cx+A, cx-A, cx+B, cx-B, cx*A, cx*B]:
		if not isRange(i) or visited[i]:
			continue
		else:
			q.append([i, cnt+1])
			visited[i] = True

print(ret)
