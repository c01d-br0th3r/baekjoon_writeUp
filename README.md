# 백준 알고리즘 라이트업 저장소

### 카카오 / 우아한형제들 코테 보고 현타와서 만들었습니다.

백준 계정 새로 팜: **c01d_br0th3r**<br />
목표: 지금까지 스터디한 문제들 싹 다 다시 풀고 구종만 알고리즘 부시기

### 특이사항

20/05/20: 소스가 너무 많아져서 `sources` 디렉토리 생성, 파일 옮김

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
