import sys
input = sys.stdin.readline

sys.setrecursionlimit(10**9)


def find(x):
    if x == city[x]:
        return x
    city[x] = find(city[x])
    return city[x]


def union(a, b):
    a = find(a)
    b = find(b)
    if a < b:
        city[b] = a
    else:
        city[a] = b


n = int(input())
m = int(input())
city = [i for i in range(n+1)]
for i in range(n):
    connect = list(map(int, input().split()))
    for j in range(n):
        if connect[j]:
            union(i+1, j+1)
plan = list(map(int, input().split()))

flag = False
tmp = city[plan[0]]
for p in plan:
    if city[p] != tmp:
        flag = True
        break

if flag:
    print("NO")
else:
    print("YES")
