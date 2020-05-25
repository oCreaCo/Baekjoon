#include <iostream>

using namespace std;

int main() {

	int a, b, v;
	cin >> a >> b >> v;

	int day = (v - b - 1) / (a - b) + 1;

	cout << day << endl;

	return 0;
}

/*
총 v만큼 올라갔다면
전날까지는 (v - b) 만큼 올라간 상태
(v - b) 까지는 하루에 (a - b) 만큼 올라갔으므로
yesterday = (v - b) / (a - b)
이때 yesterday + 1이 답이지만(전날까지 올라간 거리 (v - b)를 기준으로 계산했으므로),
만약에 yesterday가 나누어떨어진다면, 전날 밤에 미끄러진 거리 b를 빼지 않았다면 다 올랐을 것이므로
이때는 yesterday에 + 1을 하지 않는다.
이때 yesterday의 분자에 1을 빼주면 무조건 나누어 떨어지지 않으므로
분자에 1을 빼준 뒤 yesterday + 1을 해준다.
https://yahohococo.tistory.com/28
*/