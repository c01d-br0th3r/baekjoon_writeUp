#include <bits/stdc++.h>
using namespace std;

int N, K;
int W[104], V[104];
int dp[104][100004] = { 0 };
int ret;

int main() {
    scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            if (j < W[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-W[i]] + V[i]);
        }
    }
    for (int i = 0; i <= K; i++) {
        ret = max(ret, dp[N][i]);
    }
    printf("%d\n", ret);
    return 0;
}

