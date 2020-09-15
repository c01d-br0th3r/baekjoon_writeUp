#include <bits/stdc++.h>
using namespace std;

int N;
int arr[26][26];
int total, ret;
int dy[] = {0, 0, -1, 1};
int dx[] = {-1, 1, 0, 0};

void dfs(int cy, int cx, int cnt) {
    arr[cy][cx] = -1;
    ret++;
    for (int i = 0; i < 4; i++) {
        int ny = cy + dy[i];
        int nx = cx + dx[i];
        if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
        
        if (arr[ny][nx] == 1) {
            arr[ny][nx] = -1;
            dfs(ny, nx, cnt + 1);
        }
    }
}

int main() {
    vector<int> v;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) {
                dfs(i, j, 1);
                v.push_back(ret);
                total++;
                ret = 0;
            }
        }
    }
    printf("%d\n", total);
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }
    return 0;
}

