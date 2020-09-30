#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> t;
    t.push(s[0]);
    for (int i = 1; i < s.length(); i++) {
        if (!t.empty() && t.top() == s[i]) t.pop();
        else t.push(s[i]);
    }
    answer = t.empty() ? 1 : 0;
    return answer;
}
