#include <iostream>

using namespace std;

int main() {

	int n, i = 1, sum = 1;
	cin >> n;
	while (1) {
		if (n <= sum) {
			cout << i << endl;
			break;
		}
		sum += 6 * i;
		i++;
	}

	return 0;
}
