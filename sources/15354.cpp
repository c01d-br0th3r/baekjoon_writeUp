#include <bits/stdc++.h>
using namespace std;

int N;
char arr[26];

int main() {
    int cnt = 1;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        getchar();
        scanf("%c", &arr[i]);
    }
    for (int i = 1; i < N; i++) {
        if (arr[i] == arr[i-1]) continue;
        else cnt++;
    }
    printf("%d\n", cnt+1);
    return 0;
}

