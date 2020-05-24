#include <bits/stdc++.h>
using namespace std;

int K, N;
int arr[10004];

int main() {
    long long minNum = 0, midNum = 0;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    long long maxNum = LLONG_MAX;

    while (minNum <= maxNum) {
        long long cnt = 0;
        midNum = (maxNum + minNum) / 2;
        for (int i = 0; i < K; i++) {
            cnt += arr[i] / midNum;
        }
        if (cnt >= N) {
            minNum = midNum + 1;
        }
        else {
            maxNum = midNum - 1;
        }
    }
    printf("%lld\n", maxNum);
    
    return 0;
}

