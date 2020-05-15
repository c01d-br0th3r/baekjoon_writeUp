#include <bits/stdc++.h>

int N, ret;

int main() {
    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        int sum = i;
        int k = i;
        while (k > 0) {
            sum += k % 10;
            k /= 10;
        }
        if (sum == N) {
            ret = i;
            break;
        }
    }
    printf("%d\n", ret);
    return 0;
}

