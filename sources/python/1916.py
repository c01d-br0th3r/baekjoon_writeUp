import sys
from heapq import heappush, heappop
input = sys.stdin.readline

INF = 987654321

N = int(input())
M = int(input())
graph = [[] for _ in range(N+1)]
d = [INF for _ in range(N+1)]
for _ in range(0, M):
	init, arrv, value = map(int, input().split())
	graph[init].append([arrv, value])
start, end = map(int, input().split())

def dijkstra(s):
	d[s] = 0
	heap = []
	heappush(heap, [0, s])
	while heap:
		val, cx = heappop(heap)
		if d[cx] < val:
			continue
		for idx, va in graph[cx]:
			nv = val + va
			if d[idx] > nv:
				d[idx] = nv
				heappush(heap, [nv, idx])

dijkstra(start)
print(d[end])
