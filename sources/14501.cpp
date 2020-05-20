#include <bits/stdc++.h>
using namespace std;

int N;
int T[17], P[17];
int dp[17];

int main() {
    int ret = 0;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &T[i], &P[i]);
    }
    
    for (int i = 1; i <= N; i++) {
        if (i+T[i] <= N+1) {
            dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
        }
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    for (int i = 1; i <= N+1; i++) {
        ret = max(ret, dp[i]);
    }
    printf("%d\n", ret);
    return 0;
}

