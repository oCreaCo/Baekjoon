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
��Ģ�� ã���� 1 2 33 44 555 666 ���� ã���� for���� �����鼭 �ð��ʰ��� ���
�׷��� 1 3 5 7 9�� ���� �������� �������� �� �츦 ���鼭 ĳġ�ؾ��Ѵ�
http://blog.naver.com/PostView.nhn?blogId=occidere&logNo=220982644540&redirect=Dlog&widgetTypeCall=true
�׸��� ���ǿ��� 2^31������ ���� �־����ٴ°� ���� unsigned�� ĳġ�ؾ��Ѵ�
�ǹ�1 �¾�? ��Ƴ�...
*/
