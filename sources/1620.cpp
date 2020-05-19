#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> poke;
char name[24];
string pokemon[100004];
char quiz[24];

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", name);
        string Sname = name;
        poke.insert(make_pair(Sname, i));
        pokemon[i] = Sname;
    }
    for (int i = 0; i < M; i++) {
        scanf("%s", quiz);
        if (quiz[0] >= 'A' && quiz[0] <= 'Z') {
            printf("%d\n", poke[quiz] + 1);
        }
        else cout << pokemon[atoi(quiz)-1] << "\n";
    }
    
    return 0;
}

