#include <bits/stdc++.h>
using namespace std;

#define INF 1e8

int N, M;
int S, E;
vector<pair<int, int>> v[1004];
int d[1004];
int cnt;
int route[1004];
vector<int> navi;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));
    d[start] = 0;
    while (!pq.empty()) {
        int cx = pq.top().second;
        int value = pq.top().first;
        pq.pop();
        for (int i = 0; i < v[cx].size(); i++) {
            int nx = v[cx][i].first;
            int nvalue = v[cx][i].second;
            if (d[nx] > value + nvalue) {
                route[nx] = cx;
                d[nx] = value + nvalue;
                pq.push(make_pair(d[nx], nx));
            }
        }
    }
}

int main() {
    int start, end, value;
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N; i++) d[i] = INF;
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &start, &end, &value);
        v[start].push_back(make_pair(end, value));
    }
    scanf("%d %d", &S, &E);
    dijkstra(S);
    printf("%d\n", d[E]);
    int temp = E;
    while (temp) {
        navi.push_back(temp);
        temp = route[temp];
    }
    printf("%d\n", navi.size());
    for (int i = navi.size()-1; i >= 0; i--) {
        printf("%d ", navi[i]);
    }
    printf("\n");
    return 0;
}

