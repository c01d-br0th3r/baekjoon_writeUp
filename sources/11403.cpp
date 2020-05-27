#include <bits/stdc++.h>
using namespace std;

int N;
int arr[104][104];
int ret[104][104];
int visited[104];

void bfs() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            visited[j] = 0;
        }
        queue<int> q;
        for (int j = 0; j < N; j++) {
            if (arr[i][j] == 1) q.push(j);
        }
        while (!q.empty()) {
            int cx = q.front();
            ret[i][cx] = 1;
            q.pop();
            for (int j = 0; j < N; j++) {
                if (arr[cx][j] == 1 && !visited[j]) {
                    q.push(j);
                    visited[j] = 1;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", ret[i][j]);
        }
        printf("\n");
    }
    return 0;
}

