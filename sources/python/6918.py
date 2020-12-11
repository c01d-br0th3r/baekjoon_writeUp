import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
building = []
s = deque()
for _ in range(n):
    building.append(int(input()))
ret = 0
for i in range(n):
    while len(s) != 0 and s[-1] <= building[i]:
        s.pop()
    ret += len(s)
    s.append(building[i])
print(ret)
