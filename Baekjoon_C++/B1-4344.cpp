#include <iostream>

using namespace std;

int main() {

	int n;
	int tmp1 = 0;
	int tmp2 = 0;
	int tmp3 = 0;
	int sum;
	float avg;

	cin >> n;
	int* arr;
	for (int i = 0; i < n; i++) {
		cin >> tmp1;
		sum = 0;
		arr = new int[tmp1];
		for (int j = 0; j < tmp1; j++) {
			cin >> tmp2;
			arr[j] = tmp2;
			sum += tmp2;
		}
		avg = sum / tmp1;
		tmp3 = 0;
		for (int j = 0; j < tmp1; j++) {
			if (arr[j] > avg) {
				tmp3++;
			}
		}
		cout << fixed;
		cout.precision(3);
		cout << (float)tmp3 / (float)tmp1 * 100  << "%" << endl;
	}

	return 0;
}
