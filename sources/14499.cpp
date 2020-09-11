#include <bits/stdc++.h>
using namespace std;

int N, M, x, y, K;
int dice[] = {0, 0, 0, 0, 0, 0, 0};
vector<int> cmd;
int arr[24][24];
int d[][7] = {{0, 0, 0, 0}, {3, 4, 2, 5}, {3, 4, 6, 1}, {6, 1, 2, 5}, {1, 6, 2, 5}, {3, 4, 1, 6}, {3, 4, 5, 2}};
int dy[] = {0, 0, -1, 1};
int dx[] = {1, -1, 0, 0};

int main() {
    int dir;
    scanf("%d %d %d %d %d", &N, &M, &y, &x, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i = 0; i < K; i++) {
        scanf("%d", &dir);
        cmd.push_back(dir);
    }
    
    for (int i = 0; i < cmd.size(); i++) {
        int cc = cmd[i] - 1;
        int tmpDice[7] = {0, 0, 0, 0, 0, 0, 0};
        if (cc == 0) {
            tmpDice[1] = dice[4];
            tmpDice[2] = dice[2];
            tmpDice[3] = dice[1];
            tmpDice[4] = dice[6];
            tmpDice[5] = dice[5];
            tmpDice[6] = dice[3];
        }
        
        else if (cc == 1) {
            tmpDice[1] = dice[3];
            tmpDice[2] = dice[2];
            tmpDice[3] = dice[6];
            tmpDice[4] = dice[1];
            tmpDice[5] = dice[5];
            tmpDice[6] = dice[4];
        }
        
        else if (cc == 2) {
            tmpDice[1] = dice[5];
            tmpDice[2] = dice[1];
            tmpDice[3] = dice[3];
            tmpDice[4] = dice[4];
            tmpDice[5] = dice[6];
            tmpDice[6] = dice[2];
        }
        
        else if (cc == 3) {
            tmpDice[1] = dice[2];
            tmpDice[2] = dice[6];
            tmpDice[3] = dice[3];
            tmpDice[4] = dice[4];
            tmpDice[5] = dice[1];
            tmpDice[6] = dice[5];
        }
        
        int ny = y + dy[cc];
        int nx = x + dx[cc];
        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
        if (arr[ny][nx] == 0) {
            arr[ny][nx] = tmpDice[6];
        }
        else {
            tmpDice[6] = arr[ny][nx];
            arr[ny][nx] = 0;
        }
        printf("%d\n", tmpDice[1]);
        
        for (int i = 0; i < 7; i++) {
            dice[i] = tmpDice[i];
        }
        y = ny;
        x = nx;
    }
    
    return 0;
}

