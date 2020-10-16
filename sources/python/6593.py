import sys
from collections import deque
input = sys.stdin.readline


def isRange(y, x, z, ly, lx, lz):
    if y >= 0 and y < ly and x >= 0 and x < lx and z >= 0 and z < lz:
        return True
    else:
        return False


def bfs(building, q, visited, dy, dx, dz, fy, fx, fz):
    while q:
        cy, cx, cz, cnt = q.popleft()
        visited[cz][cy][cx] = True
        if cy == fy and cx == fx and cz == fz:
            return cnt

        for i in range(6):
            ny = cy + dy[i]
            nx = cx + dx[i]
            nz = cz + dz[i]
            if isRange(ny, nx, nz, R, C, L):
                if not visited[nz][ny][nx] and building[nz][ny][nx] != 1:
                    visited[nz][ny][nx] = True
                    q.append((ny, nx, nz, cnt + 1))
    return -1


dy = [-1, 1, 0, 0, 0, 0]
dx = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

while True:
    L, R, C = map(int, input().split())
    if L == 0 and R == 0 and C == 0:
        break

    building = []
    q = deque()
    fy = 0
    fx = 0
    fz = 0
    visited = [[[False for _ in range(34)]
                for _ in range(34)] for _ in range(34)]
    for i in range(L):
        floor = []
        for j in range(R+1):
            tmp = input()
            f = []
            for k in range(len(tmp)):
                if tmp[k] == '#':
                    f.append(1)
                elif tmp[k] == '.':
                    f.append(0)
                elif tmp[k] == 'S':
                    f.append(2)
                    q.append((j, k, i, 0))
                elif tmp[k] == 'E':
                    f.append(-1)
                    fy = j
                    fx = k
                    fz = i

            if len(f):
                floor.append(f)
        building.append(floor)

    ret = bfs(building, q, visited, dy, dx, dz, fy, fx, fz)
    if ret == -1:
        print("Trapped!")
    else:
        print("Escaped in", ret, "minute(s).")
