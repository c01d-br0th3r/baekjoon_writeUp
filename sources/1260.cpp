#include <bits/stdc++.h>
using namespace std;

int N, M, V;
int arr[1001][1001];
int visitedDfs[1001];
int visitedBfs[1001];

void dfs(int cx) {
    visitedDfs[cx] = 1;
    printf("%d ", cx);
    for (int i = 1; i <= N; i++) {
        if (arr[cx][i] && !visitedDfs[i]) {
            visitedDfs[i] = 1;
            dfs(i);
        }
    }
}

void bfs() {
    queue<int> q;
    q.push(V);
    visitedBfs[V] = 1;
    
    while (!q.empty()) {
        int cx = q.front();
        printf("%d ", cx);
        q.pop();
        
        for (int i = 1; i <= N; i++) {
            if (arr[cx][i] && !visitedBfs[i]) {
                visitedBfs[i] = 1;
                q.push(i);
            }
        }
    }
}

int main() {
    int a, b;
    scanf("%d %d %d", &N, &M, &V);
    for (int i = 0; i < M; i++) {
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    dfs(V);
    printf("\n");
    bfs();
    printf("\n");
    return 0;
}

