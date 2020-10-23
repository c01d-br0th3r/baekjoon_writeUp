import sys
from collections import deque
input = sys.stdin.readline

div = 1000000000

N, K = map(int, input().split())
dp = [[0 for _ in range(K+1)] for _ in range(N+1)]

for i in range(1, K+1):
    dp[0][i] = 1
for i in range(1, N+1):
    dp[i][0] = 1
    dp[i][1] = 1
    if K >= 2:
        dp[i][2] = i+1

for i in range(1, N+1):
    for j in range(3, K+1):
        idx = i
        while idx >= 0:
            dp[i][j] += dp[idx][j-1] % div
            idx -= 1

print(dp[N][K] % div)
