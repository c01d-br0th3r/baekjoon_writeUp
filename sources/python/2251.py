import sys
from collections import deque
input = sys.stdin.readline


def go(x, y):
    if not visited[x][y]:
        visited[x][y] = True
        q.append((x, y))


A, B, C = map(int, input().split())
visited = [[False] * 201 for _ in range(201)]
q = deque()
answer = []
q.append((0, 0))
visited[0][0] = True
while q:
    a, b = q.popleft()
    c = C-a-b
    if a == 0:
        answer.append(c)

    # A -> B
    if a + b <= B:
        go(0, a+b)
    else:
        go(a-(B-b), B)

    # A -> C
    if a + c <= C:
        go(0, b)
    else:
        go(a-(C-c), b)

    # B -> A
    if b + a <= A:
        go(b+a, 0)
    else:
        go(A, b-(A-a))

    # B -> C
    if b + c <= C:
        go(a, 0)
    else:
        go(a, b-(C-c))

    # C -> A
    if c + a <= A:
        go(c+a, b)
    else:
        go(A, b)

    # C -> B
    if c + b <= B:
        go(a, c+b)
    else:
        go(a, B)

answer.sort()
for elem in answer:
    print(elem, end=' ')
