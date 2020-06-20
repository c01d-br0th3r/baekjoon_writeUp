#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int N, M;
int arr[104][104];

void init() {
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            if (i == j) arr[i][j] = 0;
            else arr[i][j] = INF;
        }
    }
}

int main() {
    init();
    int start, end, value;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &value);
        if (arr[start][end] > value) arr[start][end] = value;
    }
    
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (arr[i][j] > arr[i][k] + arr[k][j]) {
                    arr[i][j] = arr[i][k] + arr[k][j];
                }
            }
        }
    }
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (arr[i][j] == INF) printf("0 ");
            else printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}

