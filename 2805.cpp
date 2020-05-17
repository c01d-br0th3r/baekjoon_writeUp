#include <bits/stdc++.h>
using namespace std;

int N, M;
int tree[1000004];

int main() {
    int minNum = 0, maxNum = -1;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &tree[i]);
        maxNum = max(maxNum, tree[i]);
    }
    while (minNum <= maxNum) {
        int midNum = (minNum + maxNum) / 2;
        long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (tree[i] > midNum) sum += tree[i] - midNum;
        }
        if (sum == M) {
            printf("%d\n", midNum);
            return 0;
        }
        
        if (sum > M)  minNum = midNum + 1;
        else maxNum = midNum - 1;
    }
    printf("%d\n", maxNum);
    
    return 0;
}

