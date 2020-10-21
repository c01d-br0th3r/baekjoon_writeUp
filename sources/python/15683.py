import sys
from copy import deepcopy
input = sys.stdin.readline

sys.setrecursionlimit(10**9)


def check(office, N, M):
    cnt = 0
    for i in range(N):
        for j in range(M):
            if office[i][j] == 0:
                cnt += 1
    return cnt


def attach(office, dirs, y, x):
    office = deepcopy(office)
    for dir in dirs:
        if dir == 0:
            for dx in range(x, len(office[0])):
                if office[y][dx] == 6:
                    break
                elif office[y][dx] != 0:
                    continue
                else:
                    office[y][dx] = '#'
        elif dir == 1:
            for dy in range(y, -1, -1):
                if office[dy][x] == 6:
                    break
                elif office[dy][x] != 0:
                    continue
                else:
                    office[dy][x] = '#'
        elif dir == 2:
            for dx in range(x, -1, -1):
                if office[y][dx] == 6:
                    break
                elif office[y][dx] != 0:
                    continue
                else:
                    office[y][dx] = '#'
        elif dir == 3:
            for dy in range(y, len(office)):
                if office[dy][x] == 6:
                    break
                elif office[dy][x] != 0:
                    continue
                else:
                    office[dy][x] = '#'
    return office


def go(office, cctv, idx, N, M):
    global ans
    if idx == len(cctv):
        ans = min(ans, check(office, N, M))
        return

    c = cctv[idx]
    kind, y, x = c

    if kind == 1:
        for i in range(4):
            new_office = attach(office, [i], y, x)
            go(new_office, cctv, idx+1, N, M)
    if kind == 2:
        for i in [(0, 2), (1, 3)]:
            new_office = attach(office, i, y, x)
            go(new_office, cctv, idx+1, N, M)
    if kind == 3:
        for i in [(0, 1), (1, 2), (2, 3), (3, 0)]:
            new_office = attach(office, i, y, x)
            go(new_office, cctv, idx+1, N, M)
    if kind == 4:
        for i in [(0, 1, 2), (1, 2, 3), (2, 3, 0), (3, 0, 1)]:
            new_office = attach(office, i, y, x)
            go(new_office, cctv, idx+1, N, M)
    if kind == 5:
        new_office = attach(office, (0, 1, 2, 3), y, x)
        go(new_office, cctv, idx+1, N, M)


ans = 1e9
N, M = map(int, input().split())
office = []
cctv = []
for i in range(N):
    tmp = list(map(int, input().split()))
    for j in range(M):
        if tmp[j] >= 1 and tmp[j] <= 5:
            cctv.append((tmp[j], i, j))
    office.append(deepcopy(tmp))

go(office, cctv, 0, N, M)
print(ans)
