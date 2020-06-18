#include <bits/stdc++.h>
using namespace std;

int N, K;
int visited[100004];

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    while (!q.empty()) {
        int cx = q.front().first;
        int cnt = q.front().second;
        if (cx == K) {
            printf("%d\n", cnt);
            break;
        }
        visited[cx] = 1;
        q.pop();
        
        if (cx + 1 < 100004) {
            if (!visited[cx+1]) q.push(make_pair(cx + 1, cnt + 1));
        }
        if (cx - 1 >= 0) {
            if (!visited[cx-1]) q.push(make_pair(cx - 1, cnt + 1));
        }
        if (cx * 2 < 100004) {
            if (!visited[cx*2]) q.push(make_pair(cx * 2, cnt + 1));
        }
    }
}

int main() {
    scanf("%d %d", &N, &K);
    bfs();
    
    return 0;
}

