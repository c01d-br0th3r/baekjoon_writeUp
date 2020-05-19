#include <bits/stdc++.h>
using namespace std;

vector<pair<int, pair<int, int>>> v;
vector<pair<int, int>> answer;
int N;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
    if (a.second.first == b.second.first) return a.second.second < b.second.second;
    return a.second.first < b.second.first;
}

bool compareIndex(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}

int main() {
    int w, h;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &w, &h);
        v.push_back(make_pair(i, make_pair(w, h)));
    }
    sort(v.begin(), v.end(), compare);
    for (int i = 0; i < N; i++) {
        int cw = v[i].second.first;
        int ch = v[i].second.second;
        int ci = v[i].first;
        int cnt = 1;
        for (int j = i+1; j < N; j++) {
            if (cw == v[j].second.first) continue;
            if (ch < v[j].second.second) cnt++;
        }
        answer.push_back(make_pair(cnt, ci));
    }
    sort(answer.begin(), answer.end(), compareIndex);
    for (int i = 0; i < N; i++) {
        printf("%d ", answer[i].first);
    }
    printf("\n");

    return 0;
}
