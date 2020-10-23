import sys
input = sys.stdin.readline

n, h = map(int, input().split())
up = [0] * (h+1)
down = [0] * (h+1)
for i in range(n):
    tmp = int(input())
    if i % 2 == 0:
        up[tmp] += 1
    else:
        down[h-tmp+1] += 1

for i in range(h-1, 0, -1):
    up[i] += up[i+1]
for i in range(2, h+1):
    down[i] += down[i-1]

total = [0] * (h+1)
for i in range(1, h+1):
    total[i] = up[i] + down[i]

ret = total[1:]
ans = min(ret)
print(ans, ret.count(ans))
