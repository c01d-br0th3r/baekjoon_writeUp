#include <bits/stdc++.h>
using namespace std;

int T;
char arr[54];

int main() {
    scanf("%d", &T);
    while (T--) {
        stack<char> s;
        scanf("%s", arr);
        int flag = 0;
        int len = strlen(arr);
        for (int i = 0; i < len; i++) {
            if (arr[i] == '(') {
                s.push(arr[i]);
            }
            else if (arr[i] == ')') {
                if (s.empty()) {
                    flag = 1;
                    break;
                }
                else s.pop();
            }
        }
        if (flag || !s.empty()) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}

