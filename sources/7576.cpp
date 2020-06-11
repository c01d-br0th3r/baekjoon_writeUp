#include <bits/stdc++.h>
using namespace std;

int M, N;
int arr[1004][1004];
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};
int visited[1004][1004];
queue<pair<int, int>> q;

void bfs() {
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        visited[cy][cx] = 1;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (arr[ny][nx] == 0 && !visited[ny][nx]) {
                    visited[ny][nx] = 1;
                    arr[ny][nx] = arr[cy][cx] + 1;
                    q.push(make_pair(ny, nx));
                }
            }
        }
    }
}

int main() {
    int ret = -1, flag = 0;
    scanf("%d %d", &M, &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 1) q.push(make_pair(i, j));
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 0) flag = 1;
            else ret = max(ret, arr[i][j]);
        }
        if (flag) break;
    }
    
    if (flag) printf("-1\n");
    else printf("%d\n", ret-1);
    
    return 0;
}

