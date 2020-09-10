#include <bits/stdc++.h>
using namespace std;

int N, K, L;
int arr[104][104];
vector<pair<int, char>> v;
int answer, direction;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};
queue<pair<int, int>> q;

int main() {
    int appleY, appleX, sec;
    char dir;
    scanf("%d\n%d", &N, &K);
    for (int i = 0; i < K; i++) {
        scanf("%d %d", &appleY, &appleX);
        arr[appleY][appleX] = -1;
    }
    scanf("%d", &L);
    for (int i = 0; i < L; i++) {
        scanf("%d %c", &sec, &dir);
        v.push_back(make_pair(sec, dir));
    }
    answer = 1;
    direction = 1;
    arr[1][1] = 1;
    int cy = 1, cx = 1, k = 0;
    while (1) {
        q.push(make_pair(cy, cx));
        int ny = q.back().first + dy[direction];
        int nx = q.back().second + dx[direction];
        if (arr[ny][nx] == 1) break;
        if (ny < 1 || ny > N || nx < 1 || nx > N) break;
        
        if (arr[ny][nx] == -1) {
            arr[ny][nx] = 1;
        }
        else if (arr[ny][nx] == 0) {
            arr[ny][nx] = 1;
            arr[q.front().first][q.front().second] = 0;
            q.pop();
        }
        
        cy = ny;
        cx = nx;
        
        if (answer == v[k].first) {
            if (v[k].second == 'L') direction = direction - 1 < 0 ? 3 : direction - 1;
            else direction = direction + 1 > 3 ? 0 : direction + 1;
            k++;
        }
        
        answer++;
    }
    
    printf("%d\n", answer);
    return 0;
}

