#include <bits/stdc++.h>
using namespace std;

#define SIZE 100001

int A, B, N, M;
int visited[SIZE];

void bfs() {
    queue<pair<int, int>> q;
    q.push(make_pair(N, 0));
    visited[N] = 1;
    
    while (!q.empty()) {
        int cx = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (cx == M) {
            printf("%d\n", cnt);
            return ;
        }
        if (cx + 1 <= SIZE && !visited[cx+1]) {
            visited[cx+1] = 1;
            q.push(make_pair(cx+1, cnt+1));
        }
        if (cx - 1 >= 0 && !visited[cx-1]) {
            visited[cx-1] = 1;
            q.push(make_pair(cx-1, cnt+1));
        }
        if (cx + A <= SIZE && !visited[cx+A]) {
            visited[cx+A] = 1;
            q.push(make_pair(cx+A, cnt+1));
        }
        if (cx - A >= 0 && !visited[cx-A]) {
            visited[cx-A] = 1;
            q.push(make_pair(cx-A, cnt+1));
        }
        if (cx + B <= SIZE && !visited[cx+B]) {
            visited[cx+B] = 1;
            q.push(make_pair(cx+B, cnt+1));
        }
        if (cx - B >= 0 && !visited[cx-B]) {
            visited[cx-B] = 1;
            q.push(make_pair(cx-B, cnt+1));
        }
        if (cx * A <= SIZE && !visited[cx*A]) {
            visited[cx*A] = 1;
            q.push(make_pair(cx*A, cnt+1));
        }
        if (cx * B <= SIZE && !visited[cx*B]) {
            visited[cx*B] = 1;
            q.push(make_pair(cx*B, cnt+1));
        }
        
    }
}

int main() {
    scanf("%d %d %d %d", &A, &B, &N, &M);
    bfs();
    return 0;
}

