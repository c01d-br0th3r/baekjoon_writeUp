#include <bits/stdc++.h>
using namespace std;

#define INF 987654321

int V, E, K;
int d[20004];
vector<pair<int, int>> v[20004];

void dijkstra() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, K));
    d[K] = 0;
    while (!pq.empty()) {
        int value = pq.top().first;
        int cx = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[cx].size(); i++) {
            int nx = v[cx][i].first;
            int nvalue = v[cx][i].second;
            
            if (value + nvalue < d[nx]) {
                d[nx] = value + nvalue;
                pq.push(make_pair(d[nx], nx));
            }
        }
    }
}

int main() {
    int start, end, value;
    scanf("%d %d", &V, &E);
    scanf("%d", &K);
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &start, &end, &value);
        v[start].push_back(make_pair(end, value));
    }
    for (int i = 1; i <= V; i++) d[i] = INF;
    dijkstra();
    for (int i = 1; i <= V; i++) {
        if (d[i] == INF) printf("INF\n");
        else printf("%d\n", d[i]);
    }
    return 0;
}

