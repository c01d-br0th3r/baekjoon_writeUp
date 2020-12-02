
import sys
import heapq
input = sys.stdin.readline


def find(x):
    if x == parent[x]:
        return x
    parent[x] = find(parent[x])
    return parent[x]


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        parent[b] = a
    else:
        parent[a] = b


def kruskal():
    ret = 0
    last = 0
    for g in graph:
        weight, src, dest = g
        if find(src) != find(dest):
            union(src, dest)
            ret += weight
            last = weight
    return ret - last


n, m = map(int, input().split())
graph = []
parent = [i for i in range(n+1)]
for _ in range(m):
    u, v, w = map(int, input().split())
    graph.append((w, u, v))
    graph.append((w, v, u))

graph.sort()
print(kruskal())
