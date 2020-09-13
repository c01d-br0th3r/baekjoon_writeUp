#include <bits/stdc++.h>
using namespace std;

int broken[10];
int N, M;
int ret;

int possible(int num) {
    if (num == 0) {
        if (broken[0] == 1) {
            return 0;
        }
        else return 1;
    }
    int len = 0;
    while (num > 0) {
        if (broken[num%10] == 1) return 0;
        len++;
        num /= 10;
    }
    return len;
}

int main() {
    int btn;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &btn);
        broken[btn] = 1;
    }
    ret = abs(N - 100);
    for (int i = 0; i < 1000000; i++) {
        if (possible(i)) {
            ret = min(ret, possible(i) + abs(N - i));
        }
    }
    printf("%d\n", ret);
    
    return 0;
}

