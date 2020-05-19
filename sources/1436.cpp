#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 666; ; i++) {
        int k = i;
        int flag = 0;
        for (int j = k; j > 0; j /= 10) {
            if (j % 10 == 6 && (j / 10) % 10 == 6 && (j / 100) % 10 == 6) {
                flag++;
                break;
            }
        }
        if (flag) cnt++;
        if (cnt == N) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

// String + find 풀이
#include <bits/stdc++.h>
using namespace std;

int N;

int main() {
    int cnt = 0;
    scanf("%d", &N);
    for (int i = 666; ; i++) {
        string s;
        s = to_string(i);
        if (s.find("666") != string::npos) cnt++;
        if (cnt == N) {
            printf("%d\n", i);
            break;
        }
    }
    return 0;
}

