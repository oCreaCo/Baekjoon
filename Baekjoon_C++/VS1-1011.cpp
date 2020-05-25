#include <iostream>

using namespace std;

int main() {

	unsigned int c, x, y, n, min, max, dist, pow, warpCount;
	cin >> c;
	for (int count = 0; count < c; count++) {
		cin >> x >> y;
		dist = y - x;
		for (n = 1;; n++) {
			pow = n*n;
			min = pow - n + 1;
			max = pow + n;
			if (min <= dist && dist <= max) {
				if (min <= dist && dist <= pow) warpCount = 2 * n - 1;
				else warpCount = 2 * n;
				cout << warpCount << endl;
				break;
			}
		}
	}

	return 0;
}

/*
규칙을 찾을때 1 2 33 44 555 666 으로 찾으면 for문을 돌리면서 시간초과가 뜬다
그래서 1 3 5 7 9를 보고 제곱수를 기준으로 좌 우를 보면서 캐치해야한다
http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220982644540&redirect=Dlog&widgetTypeCall=true
그리고 조건에서 2^31까지의 수가 주어진다는걸 보고 unsigned를 캐치해야한다
실버1 맞아? 어렵네...
*/
