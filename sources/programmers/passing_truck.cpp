
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int truck_index = 0;
    int total = 0;
    queue<int> in_bridge;
    while (1) {
        answer++;

        if (in_bridge.size() == bridge_length) {
            total -= in_bridge.front();
            in_bridge.pop();
        }

        if (truck_weights[truck_index] + total <= weight) {
            in_bridge.push(truck_weights[truck_index]);
            total += truck_weights[truck_index];
            truck_index++;
            if (truck_index >= truck_weights.size()) {
                answer += bridge_length;
                break;
            }
        }
        else {
            in_bridge.push(0);
        }
    }
    return answer;
}
