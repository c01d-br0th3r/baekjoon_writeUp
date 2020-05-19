#include <bits/stdc++.h>
using namespace std;

char S[50004];
int Q, A, B, C, D;
int alpha[27];

void init() {
    for (int i = 0; i < 27; i++) alpha[i] = 0;
}

int main() {
    scanf("%s", S);
    scanf("%d", &Q);
    while (Q--) {
        int flag = 0;
        init();
        scanf("%d %d %d %d", &A, &B, &C, &D);
        for (int i = A-1; i <= B-1; i++) alpha[S[i]-'a']++;
        for (int i = C-1; i <= D-1; i++) alpha[S[i]-'a']--;
        for (int i = 0; i < 27; i++) {
            if (alpha[i] != 0) {
                flag = 1;
                break;
            }
        }
        if (flag) printf("NE\n");
        else printf("DA\n");
    }
    return 0;
}

