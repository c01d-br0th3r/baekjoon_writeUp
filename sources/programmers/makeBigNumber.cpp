#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int len = number.length();
    int idx = 0;
    for (int i = len - k - 1; i >= 0; i--) {
        int mx = -1;
        int tmp = 0;
        for (int j = idx; j < len; j++) {
            if (j + i >= len) break;
            if (mx < number[j] - '0') {
                mx = number[j] - '0';
                tmp = j;
            }
        }
        answer += number[tmp];
        idx = tmp + 1;
    }
    return answer;
}
