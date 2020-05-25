#include <iostream>

using namespace std;

int main() {

	int c, k, n;
	cin >> c;
	for (int i = 0; i < c; i++) {
		cin >> k >> n;
		int* arr1 = new int[n];
		int* arr2 = new int[n];
		for (int j = 0; j < n; j++) {
			arr1[j] = j + 1;
		}
		for (int j = 0; j < k; j++) {
			arr2[0] = 1;
			for (int l = 1; l < n; l++) {
				arr2[l] = arr2[l - 1] + arr1[l];
			}
			for (int l = 0; l < n; l++) {
				arr1[l] = arr2[l];
			}
		}
		cout << arr2[n - 1] << endl;
	}

	return 0;
}

// 문제를 잘 읽자. 맞긴 했지만 문제를 읽어보면 동적할당으로 안풀고 array 크기를 15로 하면 된다는걸 알수있다.