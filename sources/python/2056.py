import sys
input = sys.stdin.readline

n = int(input())
times = [0] * (n+1)
graph = [[] for _ in range(n+1)]
for i in range(1, n+1):
    inp = list(map(int, input().split()))
    times[i] = inp[0]
    if inp[1] == 0:
        continue
    for j in inp[2:]:
        graph[i].append(j)

for i in range(1, n+1):
    t = 0
    if len(graph[i]) != 0:
        for j in graph[i]:
            t = max(t, times[j])
    times[i] += t
print(max(times))
