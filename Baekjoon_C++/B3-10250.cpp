#include <iostream>

using namespace std;

int main() {

	int c, h, w, n, a, b;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> h >> w >> n;
		a = n / h;
		b = n % h;
		if (b != 0) a++;
		else b = h;
		cout << b * 100 + a << endl;
	}

	return 0;
}