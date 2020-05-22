#include <bits/stdc++.h>
using namespace std;

int R, C, ret;
char arr[24][24];
char alpha[27];
int dy[] = {1, -1, 0, 0};
int dx[] = {0, 0, -1, 1};
int visited[24][24];

void go(int cy, int cx, int cnt) {
    if (cnt > ret) ret = cnt;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
            if (!visited[ny][nx] && !alpha[arr[ny][nx] - 'A']) {
                visited[ny][nx] = 1;
                alpha[arr[ny][nx] - 'A'] = 1;
                go(ny, nx, cnt+1);
                visited[ny][nx] = 0;
                alpha[arr[ny][nx] - 'A'] = 0;
            }
        }
    }
}

int main() {
    scanf("%d %d", &R, &C);
    for (int i = 0; i < R; i++) {
        scanf("%s", arr[i]);
    }
    visited[0][0] = 1;
    alpha[arr[0][0] - 'A'] = 1;
    go(0, 0, 0);
    printf("%d\n", ret+1);
    return 0;
}

