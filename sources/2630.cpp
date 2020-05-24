#include <bits/stdc++.h>
using namespace std;

int N;
int arr[130][130];
int blue, white;

void go(int n, int cy, int cx) {
    int color = arr[cy][cx];
    if (n == 1) {
        if (color == 1) blue++;
        else white++;
        return ;
    }
    for (int i = cy; i < cy + n; i++) {
        for (int j = cx; j < cx + n; j++) {
            if (arr[i][j] != color) {
                go(n/2, cy, cx);
                go(n/2, cy, cx+n/2);
                go(n/2, cy+n/2, cx);
                go(n/2, cy+n/2, cx+n/2);
                return ;
            }
        }
    }
    if (color == 1) blue++;
    else white++;
    
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    go(N, 0, 0);
    printf("%d\n%d\n", white, blue);
    
    return 0;
}

