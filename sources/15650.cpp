#include <bits/stdc++.h>
using namespace std;

int N, M;
int visited[10];

void go(int cx, int cnt) {
    if (cnt == M) {
        for (int i = 1; i <= N; i++) {
            if (visited[i]) printf("%d ", i);
        }
        printf("\n");
        return ;
    };
    for (int i = cx; i < N; i++) {
        if (!visited[i+1]) {
            visited[i+1] = 1;
            go(i+1, cnt+1);
            visited[i+1] = 0;
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    go(0, 0);
    return 0;
}

