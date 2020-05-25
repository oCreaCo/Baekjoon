#include <iostream>

using namespace std;

int main() {

	int n, i = 1, sum = 1, a, b;
	cin >> n;
	while (1) {
		if (n <= sum) {
			sum -= i;
			break;
		}
		sum += ++i;
	}

	if (i % 2 == 0) {
		a = n - sum;
		b = i - n + sum + 1;
	}
	else {
		a = i - n + sum + 1;
		b = n - sum;
	}

	cout << a << "/" << b << endl;

	return 0;
}
