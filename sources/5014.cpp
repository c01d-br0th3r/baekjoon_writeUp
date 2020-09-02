#include <bits/stdc++.h>
using namespace std;

int F, S, G, U, D;
int visited[1000004];
int ret;

void bfs() {
    ret = -1;
    queue<pair<int, int>> q;
    q.push(make_pair(S, 0));
    while (!q.empty()) {
        int cx = q.front().first;
        int cnt = q.front().second;
        if (cx == G) {
            ret = cnt;
            break;
        };
        visited[cx] = 1;
        q.pop();
        
        if (cx+U <= F && visited[cx+U] == 0) {
            q.push(make_pair(cx+U, cnt+1));
            visited[cx+U] = 1;
        }
        if (cx-D >= 1 && visited[cx-D] == 0) {
            q.push(make_pair(cx-D, cnt+1));
            visited[cx-D] = 1;
        }
    }
}

int main() {
    scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
    bfs();
    ret == -1 ? printf("use the stairs\n") : printf("%d\n", ret);
    return 0;
}

