#include <bits/stdc++.h>
using namespace std;

int N;
int arr[2204][2204];
int cnt1, cnt2, cnt3;

void go(int n, int cy, int cx) {
    int num = arr[cy][cx];
    if (n == 1) {
        if (num == -1) cnt1++;
        else if (num == 0) cnt2++;
        else cnt3++;
        return ;
    }
    
    for (int i = cy; i < cy + n; i++) {
        for (int j = cx; j < cx + n; j++) {
            if (arr[i][j] != num) {
                go(n/3, cy, cx);
                go(n/3, cy, cx+n/3);
                go(n/3, cy, cx+(n/3)*2);
                go(n/3, cy+n/3, cx);
                go(n/3, cy+n/3, cx+n/3);
                go(n/3, cy+n/3, cx+(n/3)*2);
                go(n/3, cy+(n/3)*2, cx);
                go(n/3, cy+(n/3)*2, cx+n/3);
                go(n/3, cy+(n/3)*2, cx+(n/3)*2);
                return ;
            }
        }
    }
    if (num == -1) cnt1++;
    else if (num == 0) cnt2++;
    else cnt3++;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    go(N, 0, 0);
    printf("%d\n%d\n%d\n", cnt1, cnt2, cnt3);
    
    return 0;
}

