#include <iostream>

using namespace std;

int main() {

	int Box = 0, input;
	cin >> input;

	while (1) {
		if (input % 5 == 0) {
			Box += input / 5;
			cout << Box << endl;
			break;
		}

		input -= 3;
		Box++;

		if (input < 0) {
			cout << -1 << endl;
			break;
		}
	}

	return 0;
}

// 5x + 3y = n �� �Ŀ���, ���� �� 3���� ������
// ä�� �Ÿ��� ����