#include <bits/stdc++.h>
using namespace std;

int L, C;
vector<char> v;
int acnt, bcnt;
char ret[17];
int visited[17];

void dfs(int cx, int cnt) {
    int k = 0;
    visited[cx] = 1;
    if (cnt == L - 1) {
        for (int i = 0; i < C; i++) {
            if (visited[i] == 1) {
                ret[k] = v[i];
                k++;
            }
        }
        for (int i = 0; i < L; i++) {
            if (ret[i] == 'a' || ret[i] == 'e' || ret[i] == 'i' || ret[i] == 'o' || ret[i] == 'u') acnt++;
            else bcnt++;
        }
        if (acnt >= 1 && bcnt >= 2) {
            for (int i = 0; i < L; i++) printf("%c", ret[i]);
            printf("\n");
        }
        acnt = 0;
        bcnt = 0;
        k = 0;
        return ;
    }
    for (int i = cx+1; i < C; i++) {
        visited[i] = 1;
        dfs(i, cnt+1);
        visited[i] = 0;
    }
    visited[cx] = 0;
}

int main() {
    char alp;
    scanf("%d %d", &L, &C);
    for (int i = 0; i < C; i++) {
        getchar();
        scanf("%c", &alp);
        v.push_back(alp);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i <= C-L+1; i++) {
        dfs(i, 0);
    }
    
    return 0;
}

