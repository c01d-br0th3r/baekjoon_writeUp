# 백준 알고리즘 라이트업 저장소

### 카카오 / 우아한형제들 코테 보고 현타와서 만들었습니다.

백준 계정 새로 팜: **c01d_br0th3r**<br />
목표: 지금까지 스터디한 문제들 싹 다 다시 풀고 구종만 알고리즘 부시기

***************************************************************************

### Day 1

* [BOJ 2231](https://www.acmicpc.net/problem/2231) **분해합**

쉬운 완전탐색 문제.
원래의 수에 자릿수를 쪼개 더해가며 입력값을 만들 수 있는지 확인하면 된다.
ret이 전역변수이기 때문에 만들 수 없는 경우 0으로 유지되는 것이 포인트!

* [BOJ 7568](https://www.acmicpc.net/problem/7568) **덩치**

정렬만 잘 해준 후 그대로 뽑아주면 끝!!
이를 위해 vector로 인풋을 저장하고 sort 함수를 사용했다.
한 번 틀렸는데, 문제를 대충 읽어서 키와 몸무게가 같은 경우 예외를 안 주었다.
문제를 잘 읽자..

* [BOJ 1620](https://www.acmicpc.net/problem/1620) **나는야 포켓몬 마스터 이다솜**

처음 풀었을 때에도 시간초과가 났었는데, 이번에도 그랬다..
퀴즈로 숫자가 나왔을 경우엔 O(1)로 탐색이 가능하지만
문자열을 받았을 경우 O(n^2)이 된다!! => 시간초과..
STL의 map을 사용하면 String: int의 형태로, JS의 객체처럼 쓸 수 있다는 것을 알았다.
따라서 map으로 문자열이 들어왔을 시 출력할 정수를 저장하고, 다른 string 배열에서 숫자가 들어왔을 시 문자열을 출력하도록 하면
O(1) 시간에 탐색이 가능하다.

