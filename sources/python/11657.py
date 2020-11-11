import sys
import heapq
input = sys.stdin.readline


def bellman_ford():
    global flag

    for repeat in range(n):
        for i in range(1, n+1):
            for cost, curr in arr[i]:
                if d[i] != 1e9 and d[curr] > d[i] + cost:
                    d[curr] = d[i] + cost
                    if repeat == n-1:
                        flag = False


n, m = map(int, input().split())
arr = [[] for _ in range(n+1)]
for _ in range(m):
    a, b, c = map(int, input().split())
    arr[a].append((c, b))
flag = True
d = [1e9] * (n+1)
d[1] = 0
bellman_ford()
if not flag:
    print(-1)
else:
    for value in d[2:]:
        print(value if value != 1e9 else -1)
