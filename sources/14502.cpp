#include <bits/stdc++.h>
using namespace std;

int N, M;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int arr[10][10];
int cp_arr[10][10];
vector<pair<int, int>> v;
vector<pair<int, int>> l;
int dfsVisited[70];
int ret, cnt;

void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cp_arr[i][j] = arr[i][j];
        }
    }
    cnt = 0;
}

void bfs() {
    init();
    for (int i = 0; i < l.size(); i++) {
        cp_arr[l[i].first][l[i].second] = 1;
    }
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (cp_arr[i][j] == 2) q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                if (cp_arr[ny][nx] == 0 && cp_arr[ny][nx] != 1) {
                    q.push(make_pair(ny, nx));
                    cp_arr[ny][nx] = 2;
                }
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if(cp_arr[i][j] == 0) cnt++;
        }
    }
    
    ret = max(ret, cnt);
}

void dfs(int cindex, int cnt) {
    if (cnt == 2) {
        bfs();
        return ;
    }
    for (int i = cindex + 1; i < v.size(); i++) {
        if (dfsVisited[i] == 0) {
            dfsVisited[i] = 1;
            l.push_back(make_pair(v[i].first, v[i].second));
            dfs(i, cnt + 1);
            dfsVisited[i] = 0;
            l.pop_back();
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if (arr[i][j] == 0) v.push_back(make_pair(i, j));
        }
    }
    for (int i = 0; i < v.size(); i++) {
        init();
        l.push_back(make_pair(v[i].first, v[i].second));
        dfs(i, 0);
        l.pop_back();
        dfsVisited[i] = 1;
    }
    printf("%d\n", ret);
    return 0;
}

