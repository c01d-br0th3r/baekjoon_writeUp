#include <bits/stdc++.h>
using namespace std;

int N, M;
int arr[504][504];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, 1, -1};
int dp[504][504];

void init() {
    for (int i = 0; i < 504; i++) {
        for (int j = 0; j < 504; j++) {
            dp[i][j] = -1;
        }
    }
}

int go(int y, int x) {
    if (y == 0 && x == 0) return 1;
    int &ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
            if (arr[ny][nx] > arr[y][x]) ret += go(ny, nx);
        }
    }
    return ret;
}

int main() {
    init();
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("%d\n", go(N - 1, M - 1));
    return 0;
}

