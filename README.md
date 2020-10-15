# 백준 알고리즘 라이트업 저장소

### 카카오 / 우아한형제들 코테 보고 현타와서 만들었습니다.

백준 계정 새로 팜: **c01d_br0th3r**<br />
목표: 지금까지 스터디한 문제들 싹 다 다시 풀고 구종만 알고리즘 부시기

### 특이사항

20/05/20: 소스가 너무 많아져서 `sources` 디렉토리 생성, 파일 옮김<br />
20/10/02: 파이썬 시작

## Day 1

* [BOJ 2231](https://www.acmicpc.net/problem/2231) **분해합**

쉬운 완전탐색 문제.<br />
원래의 수에 자릿수를 쪼개 더해가며 입력값을 만들 수 있는지 확인하면 된다.<br />
`ret`이 전역변수이기 때문에 만들 수 없는 경우 0으로 유지되는 것이 포인트!<br />

* [BOJ 7568](https://www.acmicpc.net/problem/7568) **덩치**

정렬만 잘 해준 후 그대로 뽑아주면 끝!!<br />
이를 위해 `vector`로 인풋을 저장하고 `sort` 함수를 사용했다.<br />
한 번 틀렸는데, 문제를 대충 읽어서 키와 몸무게가 같은 경우 예외를 안 주었다. 문제를 잘 읽자..<br />

* [BOJ 1620](https://www.acmicpc.net/problem/1620) **나는야 포켓몬 마스터 이다솜**

처음 풀었을 때에도 시간초과가 났었는데, 이번에도 그랬다..<br />
퀴즈로 숫자가 나왔을 경우엔 O(1)로 탐색이 가능하지만 문자열을 받았을 경우 O(n^2)이 된다!! => 시간초과..<br />
STL의 `map`을 사용하면 `String: int`의 형태로, JS의 객체처럼 쓸 수 있다는 것을 알았다.<br />
따라서 `map`으로 문자열이 들어왔을 시 출력할 정수를 저장하고, 다른 string 배열에서 숫자가 들어왔을 시 문자열을 출력하도록 하면<br />
O(1) 시간에 탐색이 가능하다.<br />

***************************************************************************

## Day 2

* [BOJ 1436](https://www.acmicpc.net/problem/1436) **영화감독 숌**

범위가 적당하고 시간도 충분하니 브루트포스하면 된다.<br />
첫 번째 풀이는 나머지 연산자를 통해 연속된 6이 3개이면 카운트를 올리는 방식으로 전부 찾았고,<br />
두 번째 풀이는 C++의 `string`과 `find` 함수를 이용해서 구헀다.<br />
실행 시간을 비교해봤는데 전자가 6배정도 빨랐다.. 알아두자!!

* [BOJ 2805](https://www.acmicpc.net/problem/2805) **나무 자르기**

처음 풀었을 때에도 시간초과가 발생했던 기억이 있는 문제.<br />
이번에도 역시 시간초과였다. 이분탐색을 구현할 때 `mid+1`이나 `mid-1`값으로 바꿔줘야 하는데 계속 현재값+1로 한다..<br />
관련 문제들을 풀어보며 확실하게 익히고 넘어가야 할 것 같다ㅠㅠ

* [BOJ 1260](https://www.acmicpc.net/problem/1260) **DFS와 BFS**

DFS, BFS 알고리즘을 처음 접한 것이 벌써 작년이다!!<br />
그 땐 `Queue` 라는 자료구조도 뭔지 모른 채 C언어로 함수 하나하나 작성해가며 구현했던 아픈 기억이 있다..<br />
C++의 STL 사용법을 익히니 재귀를 이용하는 DFS보다 BFS가 쉽고 가볍게 느껴진다🙂

***************************************************************************

## Day 3

* [BOJ 15354](https://www.acmicpc.net/problem/15354) **Aron**

코딩 시간보다 문제 읽는 시간이 오래 걸렸다.<br />
단순 반복분 연습 문제여서 넘어가도 될 듯?

* [BOJ 15355](https://www.acmicpc.net/problem/15355) **Programiranje**

문자열 처리라고 말하기도 애매한 문자열 처리 문제였다.<br />
문자열을 두 번 파싱해서 얘네들이 순서를 바꿔도 같은 문자열이면 "DA"를, 아니면 "NE"를 출력하면 끝!!<br />
순서를 바꿔도 같은지 확인하려면 각 문자열의 알파벳 개수가 똑같은지 살펴보면 된다.<br />
공간을 줄이기 위한 팁이 있었는데, 첫 번째 문자열에선 해당 알파벳 인덱스를 ++, 두 번째 문자열에선 해당 알파벳 인덱스를 -- 연산하면<br />
해당 알파벳 인덱스가 0일 때만 같은 수만큼 들어있다는 뜻이 된다!! 기억하자.

* [BOJ 12761](https://www.acmicpc.net/problem/12761) **돌다리**

(또) 문제를 안 읽어서 1시간가량 삽질한 문제.<br />
문제도 정말 단순하고, 주미에게 도달하지 못하는 경우도 없고, 범위도 적당 + 시간도 충분하기 때문에 BFS로 완전탐색 해주면 된다.<br />
DFS를 사용하지 않은 이유는 8가지나 되는 이동방법 중 하나만 파서 끝까지 가는 것이 너무나도 비효율적이기 때문!!<br />
이 쉬운 문제를.. 문제 첫 줄에 `돌의 번호는 0 부터 100,000 까지 존재하고` 란 조건을 안읽어서 실컷 삽질했다..<br />
당연히 인덱스를 넘어갈 수 있다고 생각해서 범위를 최댓값인 `30 * 100000`으로 잡아버렸다.<br />
십만을 넘어서는 범위를 설정할 시 답보다 더 작은 경우의 수가 나올 수 있는 것 같다.<br />
카카오 코테에서도 문제 안 읽어서 신나게 삽질했는데ㅠㅠㅠ 문제 읽자, 또 읽자 제발 읽자ㅠ

***************************************************************************

## Day 4

* [BOJ 9012](https://www.acmicpc.net/problem/9012) **괄호**

스택을 처음 배울 때 무조건 응용문제로 나오는 괄호 문제.<br />
`(`가 들어오면 `push`, `)`가 들어오면 `pop` 해주고, 스택이 비어있는데 `pop`을 시도하거나 반복문이 끝나도 스택이 비어있지 않으면<br />
완벽한 괄호라고 할 수 없다. 따라서 `flag`를 설정해서 분기를 나눠주면 끝나는 간단한 문제이다.<br />
이것도 처음 풀 땐 스택을 하나하나 구현했는데, 이번엔 STL을 사용해서 풀었다!!

* [BOJ 14501](https://www.acmicpc.net/problem/14501) **퇴사** **(✔️ 다시 풀기)**

DP 문제, 두 번째 푸는 것인데도 못 풀었다..<br />
처음 풀었을 때 워낙 충격적이어서 아이디어는 기억에 남았지만 구현을 못했다.<br />
그 날 일을 했을 때와 안 했을 때를 나누는 거였는데.. 하다가 예제 4번에서 멘탈이 으깨져서 못 풀었다ㅠ<br />
N+1날 돈을 받는다고 생각하고 `dp[i+T[i]]`를 갱신하는 것 까진 좋았다. 그 후 **그 날 일을 안했을 때** 에서 막힌 것 같다.<br />
나는 당연히 `dp[i] = max(dp[i], dp[i-1])`로 구현했다. 일을 안했으면 전날의 값과 똑같겠네~ 하면서 말이다.<br />
이렇게 하면 당연히 안되는게, 처음 설정을 **N+1날 돈을 받는다.** 라고 해놓았기 때문이다.<br />
다음 날 받을 돈을 갱신해야 하는데 그 날 받을 돈을 갱신하니깐 당연히 틀린 값이 나온다.. 허무한데 이걸 못 떠올렸다는게 참 안타깝다ㅠ<br />
나중에 이 문제를 다시 풀어본다고 해도 막힘없이 코드를 작성할 자신이 없다..😞 DP는 볼 때마다 새롭다는게 이런건가..<br />
처음 설정한 논리대로 따라가자. 몇 주후 다시 이 문제를 풀어봐야겠다.

* [BOJ 1987](https://www.acmicpc.net/problem/1987) **알파벳**

단순 백트래킹 문제인데 난이도가 무려 Gold 4.. 위에 퇴사 문제보다 훨씬 간단하고 직관적이다.<br />
첫 시작점이 (0, 0) 고정이므로 이 곳은 백트래킹 할 필요 없이 방문 처리를 해준다. 물론 알파벳도 같이!!<br />
그 후 DFS를 돌리는데, 이걸 선택한 이유는 시작점에서 갈 수 있는 한 끝까지 간 후 카운트를 계산해야하기 때문.<br />
어짜피 더 갈 곳이 없으면 함수가 끝나기 때문에 베이스케이스를 설정할 필요도 없다.<br />
그냥 상하좌우 탐색 후 `1) 방문하지 않았고 2) 해당 알파벳이 나온 적이 없다`면 재귀로 들어간다.<br />
탐색 후엔 방문했던 지점과 알파벳을 0으로 초기화해준다. 그래야만 시작점에서 다른 곳으로 갈 때 충돌나지 않기 때문이다!!

***************************************************************************

## Day 5
* [BOJ 15650](https://www.acmicpc.net/problem/15650) **N과M(2)**

단순 백트래킹 2번째 문제. 구현 중 변수를 잘못 써서 20분정도 삽질했다 ㅋㅋㅋㅋ <br />
`visited` 배열을 선언해서 M번 재귀호출 후 방문한 곳을 출력, 그 후 백트래킹으로 배열을 초기화해주면 된다.<br />
간단하니깐 넘어가도 좋을듯!!

* [BOJ 2630](https://www.acmicpc.net/problem/2630) **색종이 만들기** **(✔️ 비슷한 문제 풀기)**

분할정복이 왜 이렇게 낯선지 모르겠다ㅠㅠㅠㅠ 재귀 개념이 약해서 그런지, 연습을 많이 안해서 그런지..<br />
공식이 안 보인다고 해야되나? 아무튼 4방향 재귀를 구현하는데 코드가 잘 나오지 않는다. 비슷한 문제 두 개정도 찾아서 풀어야겠다ㅠㅠ<br />
인자로 길이와 현재 y, x값을 주고 그 좌표값 + 길이를 반복문으로 돌려가며 같은 색만 나오는지 아닌지 검사한다.<br />
다른 색이 나오면 그 즉시 이분탐색을 돌고, 리턴을 이용해 함수를 종료해서 무한루프를 막는다.<br />
같은 색만 나왔다면 for문을 무사히 탈출했다는 것이니깐 카운트를 올려주면 끝!! 비슷한 문제를 많이 풀어보자 ㅠㅠ

* [BOJ 1654](https://www.acmicpc.net/problem/2630) **랜선 자르기**

분할정복 중 이분탐색 문제로, 답이 이 쯤이겠지? 란 유추를 기반으로 따져보면 된다.<br />
최솟값과 최댓값을 갱신하면서 중간값을 계산해주고, 이 값으로 나눠봤을 때 갯수에 맞는지를 판단한다.<br />
이분탐색을 구현할 땐 특히 자료형과 언제 반복문을 탈출할 것인지 잘 생각해야 한다. 실수하면 한 순간에 틀린 답이 되기 때문에ㅠㅠ<br />
그나마 이 문제를 풀면서?.. 삽질해보면서 어떻게 접근해야 하고 실제로 이분탐색이 어떻게 이루어지는지 확인할 수 있었다. 열심히 하자ㅠ<br />


* [BOJ 2580](https://www.acmicpc.net/problem/2580) **스도쿠**

못풀었다.. 나중에 풀어보자ㅠ

*****************************************************************************

## Day 6

* [BOJ 1780](https://www.acmicpc.net/problem/1780) **종이의 개수**

2630번과 거의 똑같은 문제. 확실히 개념을 잡고 가니 코드 짜기가 편해졌다!! 약간 공식화가 된 것 같다.<br />
n이 1일 땐 해당 값의 cnt를 올리고, 아니라면 범위를 돌며 다른 값이 나오나 탐색한다. 나왔다면 분할 후 리턴.<br />
for문에서 리턴되지 않고 빠져나왔다면 모두 같은 색이란 뜻이므로 해당 값의 cnt를 올려주면 끝!

* [BOJ 2293](https://www.acmicpc.net/problem/2293) **동전1**

다이나믹 프로그래밍 하면 떠오르는 대표 문제이다. 이 문제도 처음 풀 때 충격이 너무 심해서 풀이를 머리에 박아놨다 ㅋㅋㅋ <br />
처음엔 왜 이렇게 되는지 이해가 전혀 안돼서 유튜브로 강의까지 찾아봤었다. 포인트는 dp 배열을 계속 갱신해 주는 것!! <br />
첫 번째 동전만 써서 1~k원까지 만들 수 있는 경우를 다 저장하고, 두 번째 동전까지 써서 만들 수 있는 경우의 수를 더해준다. 이렇게 계속 해주면 끝..<br />
`dp[j] += dp[j-coin[i]]` 란 공식이 만들어지는데, `dp[j-coin[i]]`는 이전 동전까지 써서 (현재 가치 - 현재 동전 가치)를 만드는 경우의 수이다. <br />
이 경우의 수에 현재 동전 가치만 더해주면 구하고자 하는 가치가 나오기 때문에 배열을 갱신해주면 된다.<br />
말로 설명하려니 굉장히 복잡하지만.. 표로 직접 그려보면 굉장히 직관적으로 보인다!! 직접 해보자.

* [BOJ 3850](https://www.acmicpc.net/problem/3850) **Jumping Monkey**

*****************************************************************************

## Day 7

* [BOJ 11403](https://www.acmicpc.net/problem/11403) **경로 찾기**

단순 BFS 문제인데 `visited` 배열을 잘못 처리해서 삽질한 문제.. <br />
각 행마다 BFS를 돌려서 갈 수 있는 모든 곳을 체크해주면 된다. 단, 행이 바뀔 때마다 `visited` 배열을 초기화해주지 않으면<br />
첫 번째 행만 제대로 나오는 대참사가 일어난다ㅠㅠ 이것 때문에 1시간 정도 삽질했다.

* [BOJ 17027](https://www.acmicpc.net/problem/17027) **Shell Game**
* [BOJ 15591](https://www.acmicpc.net/problem/15591) **MooTube (Silver)**

*****************************************************************************

## Day 8

* [BOJ 7576](https://www.acmicpc.net/problem/7576) **토마토**

2주만에 푼 알고리즘 문제이지만 쉬운 BFS 문제라 5분컷 했다!!<br />
시작점이 여러 곳이 될 수 있기 때문에 토마토가 들어있는 모든 칸의 좌표를 큐에 넣는 것부터 시작한다.<br />
이 친구들이 배열을 돌면서 인접한 토마토들을 익힌다. 이 때 익힘을 당하는(?) 토마토는 이전 토마토가 익은 날짜 + 1번 째 날에 익혀진다!!<br />
결국 마지막에 익혀진 토마토 -1이 최소 일수가 된다. 시작점이 1이기 때문에 -1을 해주는 것. EZ.

* [BOJ 1759](https://www.acmicpc.net/problem/1759) **암호만들기**

BFS에 이어서 나온 DFS 문제, 말은 어렵지만 풀이 자체는 굉장히 간단한다.<br />
오름차순으로만 암호가 이루어져 있다고 하니 1차적으로 걸러주자. 빠르고 간편하게 정렬하기 위해 `vector`를 사용했다.<br />
방문 연산 후 백트래킹을 이용해 방문하지 않았던 것으로 만들어준다.<br />
이렇게 하면 모든 경우의 수를 중복되지 않게 찾을 수 있다.<br />
최소 자음 / 모음 규칙이 들어있기 때문에 `cnt == L`일 경우일 때 걸러주면 끝!

* [BOJ 2662](https://www.acmicpc.net/problem/2662) **기업투자**

*****************************************************************************

### Day 9

 * [BOJ  1697](https://www.acmicpc.net/problem/1697) **숨바꼭질**
 
 다시 풀어보면서 느끼는건데, 정말 BFS / DFS 문제를 많이 풀었다. 기초적인 BFS는 눈 감고도 짤 수 있을 것 같다ㅋㅋ <br />
 문제의 핵심은 모든 경우를 돌며 가장 먼저 K에 도달하는 순간 cnt를 출력하는 것이다. 최소 이동거리가 필요하므로 BFS가 적합하다. <br />
 시작할 때 `using namespace std;`를 안 적어놔서 `pair`가 인식이 안 됐다. 이거 찾는 시간이 더 오래 걸린 듯? 🙃
 
 * [BOJ 11404](https://www.acmicpc.net/problem/11404) **플로이드**
 
 가장 기본적인 플로이드-와샬 알고리즘 문제. 그래프 이론을 공부할 때 대표적으로 나오는 것이 다익스트라랑 플로이드-와샬인데<br />
 솔직히 처음엔 하나도 이해를 못 했다. DP 개념도 부족했고 동작 원리를 이해하는 대신 암기하려 했기 때문이다.<br />
 그래서 이번엔 [동빈나 알고리즘 강의](https://m.blog.naver.com/ndb796/221234427842)를 들었는데 뭔가 느낌이 확 왔다!!<br />
 다익스트라 알고리즘과의 차이점은 `하나의 정점에서 최단경로를 찾느냐` vs `모든 정점에서 최단경로를 찾느냐` 이다.<br />
 3중 for문으로 구현하는데 거쳐가는 노드를 가장 바깥 쪽 for문에 설정해놓는다.<br />
 그 후 시작점에서 도착점까지 바로 가는 것이 작은지, 위에서 언급한 노드를 거쳐가는 것이 작은지 판단하면 끝!
 
 * [BOJ  1753](https://www.acmicpc.net/problem/1753) **최단경로**
 
 특정 정점에서 다른 정점으로 가는 최단거리를 구하는 다익스트라 알고리즘이다.<br />
 그러나 최댓값이 20000 이므로 배열이나 벡터로 선언하면 메모리 초과가 발생한다 ㅠㅠ <br />
 처음으로 우선순위 큐를 사용해봤는데 사용법이 익숙치 않아 오래 걸렸다. 애초에 이걸로 다익스트라를 구현한다는 것 자체가 충격이었다.<br />
 어렵게 생각하지 말고, 단지 최소 비용을 가지는 정점을 찾기 위해 사용했다고 생각해야겠다.<br />
 우선순위 큐를 사용하면 자연스럽게 최소 비용의 정점이 top에 위치하니깐 그 이후는 일반 다익스트라와 똑같기 때문이다!!
 
 
*****************************************************************************

### Day 10
 
* [BOJ 2022](https://www.acmicpc.net/problem/2022) **사다리**
* [BOJ 14502](https://www.acmicpc.net/problem/14502) **연구소**

DFS와 BFS를 혼합한 문제. 사실 백트래킹만 잘 넣어주면 어렵지 않게 풀 수 있는 문제다.<br />
처음 이 문제를 접했을 땐 푸는데 굉장히 오래 걸렸었다. 그 땐 완전탐색이 익숙하지 않아서 어디가 틀렸는지도 모른 채 무작정 코딩했기 때문인 것 같다.<br />
이번엔 나름대로 계획을 세운 후 코드를 짰다. 문제의 관건은 3개의 벽을 어떻게 선택하냐인데,<br />
일단 3개의 벽 좌표를 벡터에 넣어두고 백트래킹 하는 방식으로 시작했다. DFS를 이용해 값이 0인 3개의 좌표를 고른 후 이걸 `l` 벡터에 넣는다.<br />
BFS 시작 전 `l` 벡터에 있는 좌표들의 값을 1로 바꾼 후 BFS를 돌린다. 마지막에 0의 개수를 세며 `ret` 값을 갱신한다.<br />
여러 개의 태스트케이스를 돌려야 하므로 `init()` 함수에서 `cp_arr` 배열을 항상 처음에 입력받았던 배열로 초기화해주어야 한다.<br />
복잡하지만 논리가 확실했던 문제였다.

* [BOJ 1520](https://www.acmicpc.net/problem/1520) **내리막길**

*****************************************************************************

### ~ing

* [BOJ 5014](https://www.acmicpc.net/problem/5014) **스타트링크**

BFS 문제, 갈 수 있는 모든 경우의 수를 따져보면 된다. `pair` 를 이용해서 각각의 cnt를 저장해주고 가장 먼저 G에 도달하면 출력한다.

* [BOJ 12865](https://www.acmicpc.net/problem/12865) **평범한 배낭**

정말 이해하기 힘들었던 냅색 문제. 핵심은 `dp` 배열을 어떻게 두느냐인데, i번째 케이스를 담을 수 있는 무게로 두면 좋다.

편의를 위해 dp[0][0], dp[0][1] ... dp[0][K] 까지는 0으로 둔다.
이후 첫 번째 케이스를 도는데, dp[1][0], dp[1][1] ... dp[1][K] 까지 무게를 초과하면 dp[i-1][j] 를 그대로 가져오고,
아니면 `dp[i-1][j]`와 `dp[i-1][j-W[i]] + V[i]` 를 비교해서 갱신한다.

이중 반복문으로 풀 수 있는 냅색 문제였다.

* [BOJ 11779](https://www.acmicpc.net/problem/11779) **최소비용 구하기**

다익스트라 알고리즘을 응용해서 풀어보자!! 라고 했지만 생각대로 잘 안풀렸던 문제.
컨셉 자체는 기본적인 다익스트라와 다른 것이 없어서 그대로 구현했지만 경로를 어떻게 추적해야할지 감을 못 잡았었다.
방법은 `route` 배열을 잡아 갱신이 일어날 때마다 `route[nx] = cx` 로 저장을 해주는 것이다.
갱신이 일어났다는 것 자체가 최단거리 경로라는 것이고, 이는 `temp = route[temp]` 와 같이 역추적이 가능하다.
아직은 정신없고 어색하지만 계속 보면서 익숙해지자 ..

* [BOJ 3190](https://www.acmicpc.net/problem/3190) **뱀**

큐를 사용하면 쉽게 풀리는 문제였다. 아이디어를 떠올리기가 굉장히 힘들었는데, 구현을 하다 보니 지나온 루트에 대해 트래킹을 할 필요를 느꼈다.
처음엔 head와 tail을 저장할까 하다가 tail을 갱신할 방법이 없어서 많이 고민했다.
좌표를 저장하는 방식으로 하자고 생각하니 바로 큐가 떠올랐다. q.back()은 머리의 좌표, q.front()는 꼬리의 좌표로 두면 편해진다.
사과가 아닌 경우엔 q.front()를 pop하고 0으로 만든다. 이러면 자연스럽게 트래킹도 되기 때문에 구현만 하면 끝!

* [BOJ 14499](https://www.acmicpc.net/problem/14499) **주사위 굴리기**

너무 어렵게 생각해서 못 푼 문제. 어떻게 하면 최적화된 풀이를 짤 수 있을까 고민하다가 쉬운 부분을 놓쳤다.
주사위는 방향에 따라 동서남북이 달라지니 방향 생각하고, 그에 따른 규칙 생각하고.. 하다가 2시간을 넘겨버렸다.
문제를 푸는 키는 `tmpDice` 란 임시 주사위를 만들고, 1/2/3/4/5/6의 위치를 고정해놓은 다음
방향에 따라 원래 주사위의 어떤 칸이 들어올 것인지 대입해주면 됐다.
앞으로 주사위 문제 풀 땐 이 방법을 자주 써야겠다!!

* [BOJ 1107](https://www.acmicpc.net/problem/14499) **리모컨**

예전에 도전했다가 못 풀어서 와 이건 내 수준이 아니다 헀었던 문제.
이번에도 몇 시간동안 고민하다가 못 풀었는데, 풀이를 보니 너무 단순해서 당황했다.
핵심은 "1. 100에서 +나 -만 눌러서 원하는 번호에 도착하는 경우" / "2. 특정 번호를 누른 후 +나 -로 도착하는 경우"를 비교하는 것이다.
고민했던 부분은 2번에서 "특정 번호"를 어떻게 구할까? 였다. 뭔가 복잡한 수학이 들어갈 것 같고,
찾다보면 규칙이 보이지 않을까..? 란 생각에 삽질을 많이 하였다.
결론은 그런 것 없고, 그냥 0부터 1000000까지 다 구해보면 되는 것이었다.. 브루트 포스..
채널 0번부터 1000000번까지 전부 찾아본다.
우선 해당 번호가 숫자 버튼으로 갈 수 있는지 구한다. 그 함수는 갈 수 없으면 0을, 갈 수 있으면 숫자의 길이를 리턴한다.
그 다음엔 1번 케이스를 넣어준다. `abs(N - 100)` 이 될 것이다.
그 후 처음부터 끝까지 반복문을 도는데, 핵심은 **i번에서 N까지 가는 최솟값**을 구하는 것이다.
i를 숫자를 눌러 갈 수 있다면 `possible(i) + abs(N - i)` 가 최소 횟수일 것이다.
얘랑 최초 케이스랑 비교를 계속 해주면 된다. 그러면 어느 순간, 특정 번호에 갔을 때 최솟값이 저장될 것이다.

* [Programmers](https://programmers.co.kr/learn/courses/30/lessons/42583) **다리를 지나는 트럭**

Level 2이고, 누가 봐도 큐를 쓰세요!! 하는 문제여서 쉽게 풀 수 있을 줄 알았지만.. 풀이를 봐버렸다..
복잡하게 생각했던 것이 문제였던 것 같다. 큐를 정의할 때 카운트를 어떻게 계산하지? 반복문을 몇 개 돌려야 하지? 등등 수많은 생각을 했다.
그래서 문제가 더 복잡해졌던 것 같다. 풀이의 핵심은, 다리에 트럭이 들어갈 수 없는 경우에 0을 삽입하는 것이다.
이렇게 되면 들어간 트럭은 점점 다리의 끝으로 밀리게 될 것이고, 몇 초가 걸렸는지 쉽게 계산할 수 있다.
아이디어 싸움이다 결국.. 열심히 연습하자ㅠㅠ

* [Programmers] (https://programmers.co.kr/learn/courses/30/lessons/42746) **가장 큰 수**

아이디어조차 떠오르지 않았던 문제. 정렬 카테고리인데 어떻게 정렬해야 할지 감도 안 왔고 그냥 못 풀었다ㅠㅠ
풀이를 참고했는데, 최대 4자리 수이기 때문에 모든 숫자를 4자리로 맞춰서 내림차순 정렬하면 끝나는 문제였다.
4자리로 맞출 때 단순히 0을 추가하는 것이 아니라 47 -> 4747, 538 -> 5385 처럼 만든다.
예외도 깔끔하게 처리되고 코드도 직관적으로 잘 작성된다.. 이런 아이디어는 어디서 나오는 것인지 참ㅠㅠ
다른 분들의 풀이를 봤는데, 5줄이면 끝나더라. sort 함수를 잘 사용하시던데, 이 수준 가려면 멀었다.

* [Programmers] (https://programmers.co.kr/learn/courses/30/lessons/42883) **큰 수 만들기**

처음엔 재귀로 풀었지만 11번 TC 빼곤 전부 시간초과 / 틀렸습니다가 나왔다. 나름 dfs 잘 만들었다고 생각했는데 카테고리가 그리디였다.
DP가 베이스로 깔린 채 들어가는 그리디이기 때문에 각 케이스마다 어떤 조건이 답으로 이어지는지 찾아야 했다.
풀이의 핵심은 총 만들어야 하는 글자수를 가지고 장난질을 치는 것인데, `"4177252841", 4`로 예를 들어보자.
우선 순서가 바뀌면 안 되니까 적정 범위에서 큰 수를 골라야하는데, 6자리 수를 만들어야 하는 조건 때문에 `41772` 중에서 하나를 무조건 골라야한다.
그 이후의 숫자를 고르면 절대 6자리 수를 만들 수 없기 때문.
2번 인덱스인 `7`을 고르고, 그 다음 인덱스부터 `5`까지 `725 / 2841`에서 전자의 큰 수를 고른다.
이런 식으로 한 자리씩 채워나가면 답이 된다. 작은 문제가 큰 문제의 정답으로 이어지는 마법, 그리디 알고리즘이다.
생각보다 구현이 헷갈렸다. 연습 부족인 것 같으니 


* [Programmers] (https://programmers.co.kr/learn/courses/30/lessons/12973) **짝지어 제거하기**

생각없이 이중 반복문으로 짰다가 시간초과 엄청 떴던 문제. 스택을 떠올렸다면 바로 풀 수 있었겠지만 아직 그 수준이 아닌 것 같다.
사실 괄호 문제랑 똑같이 짝이 맞으면 지워주는, 어떤 문자열이 나오는지 관심도 없는 문제이기 때문에 스택으로 풀면 됐지만
하나하나 돌려보며 되나 안되나 따져보니 시간이 오래 걸렸다.
자료구조를 먼저 생각해보자.. 큐나 스택을 쓰면 편하지 않을까란 생각을 꼭 하고 PS를 시작하자ㅠㅠ

* [Programmers] (https://programmers.co.kr/learn/courses/30/lessons/67257) **수식 최대화**

어떻게 푸는지 감도 안 왔던 문제. 파이썬의 itertools가 얼마나 강력한 것인지 알 수 있었다..
접근 방법은 좋았다. 연산자와 숫자를 나누어 리스트에 저장하는 것 까지는 좋았다.
그 이후는 구현 자체도 못 했는데.. 방법은 다음과 같다.
먼저 ['+', '-', '*'] 를 설정해놓고 permutations로 완전탐색을 돌린다.
그 후 cp_parse를 갱신해가며 인덱스까지 돌린다. 리스트의 슬라이싱을 이용하면 쉽게 갱신이 가능하다.


* [BOJ 2251](https://www.acmicpc.net/problem/2251) **물통**

분명 풀었던 문제인데 또 틀렸다. 조건 열심히 나누고 있었는데 틀렸습니다 나온 후 1차 멘붕, BFS라는 것을 보고 2차 멘붕이었다.
핵심은 A, B에 담긴 물의 양을 기준으로 visited 배열과 queue를 할당하는데,
A->B, A->C, B->A, B->C, C->A, C->B 여섯 가지 경우를 전부 따져주면 된다.
여기서 중요한 점은 해당 물통에 물이 모두 들어갈 수 있는지 없는지 따져서 조건문으로 분기해야 한다는 것이다.
점화식 구하는 것도 좋지만, 징검다리나 이런 문제 보이면 바로 완전탐색부터 해보자. 범위 꼭 보고..
