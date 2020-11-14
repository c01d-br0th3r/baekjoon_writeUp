import sys
input = sys.stdin.readline

INF = 1e9


def bell(graph, n):
    flag = False
    d = [INF] * (n+1)
    for i in range(n+1):
        for j in range(n+1):
            for val in graph[j]:
                v, nx = val
                if d[nx] > d[j] + v:
                    d[nx] = d[j] + v
                    if i == n-1:
                        flag = True
    return flag


tc = int(input())
while tc:
    n, m, w = map(int, input().split())
    dic = dict()
    arr = [[0] * (n+1) for _ in range(n+1)]
    graph = [[] for _ in range(n+1)]
    for _ in range(m):
        s, e, t = map(int, input().split())
        if arr[s][e] == 0:
            arr[s][e] = t
            arr[e][s] = t
        else:
            arr[s][e] = min(arr[s][e], t)
            arr[e][s] = min(arr[e][s], t)
    for _ in range(w):
        s, e, t = map(int, input().split())
        arr[s][e] = min(arr[s][e], -t)

    for i in range(n+1):
        for j in range(n+1):
            if arr[i][j] != 0:
                graph[i].append((arr[i][j], j))

    if bell(graph, n):
        print("YES")
    else:
        print("NO")
    tc -= 1
