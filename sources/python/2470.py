import sys
input = sys.stdin.readline

INF = 1e12

N = int(input())
v = list(map(int, input().split()))
abs_v = []
for elem in v:
    abs_v.append([abs(elem), elem])
abs_v.sort()
ret = INF
v1 = -1
v2 = -1
for i in range(len(abs_v) - 1):
    e1 = abs_v[i][1]
    e2 = abs_v[i+1][1]
    if abs(e1 + e2) < ret:
        v1 = e1
        v2 = e2
        ret = abs(e1 + e2)

ans = sorted([v1, v2])
print(ans[0], ans[1])
