import sys
input = sys.stdin.readline

def isVow(a):
	if a == 'a' or a == 'e' or a == 'i' or a == 'o' or a == 'u':
		return True
	else:
		return False

L, C = map(int, input().split())
possible = input().split()
visited = [False] * C
possible.sort()
def dfs(cx, cnt):
	if cnt == L - 1:
		TC = []
		c = 0
		v = 0
		for i in range(C):
			if visited[i]:
				TC.append(possible[i])
		for i in range(len(TC)):
			if isVow(TC[i]):
				v += 1
			else:
				c += 1
		if c >= 2 and v >= 1:
			for i in range(len(TC)):
				print(TC[i], end='')
			print('')
		return 0

	visited[cx] = True
	for i in range(cx+1, C):
		visited[i] = True
		dfs(i, cnt+1)
		visited[i] = False
	visited[cx] = False

for i in range(0, C):
	dfs(i, 0)


	
	
