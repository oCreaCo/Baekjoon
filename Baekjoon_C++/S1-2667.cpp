#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#include <algorithm>

using namespace std;

int n, cnt = 0;
int visit[25][25] = { 0 };
int** Map;
vector<int> cnts;

void DFS(int a, int b) {
	visit[a][b] = 1;
	if (a > 0 && Map[a - 1][b] == 1 && visit[a - 1][b] == 0) DFS(a - 1, b);
	if (b < n - 1 && Map[a][b + 1] == 1 && visit[a][b + 1] == 0) DFS(a, b + 1);
	if (a < n - 1 && Map[a + 1][b] == 1 && visit[a + 1][b] == 0) DFS(a + 1, b);
	if (b > 0 && Map[a][b - 1] == 1 && visit[a][b - 1] == 0) DFS(a, b - 1);
	cnt++;
}

int main() {

	cin >> n;

	Map = new int*[n];
	for (int i = 0; i < n; ++i) {
		Map[i] = new int[n];
		memset(Map[i], 0, sizeof(int)*(n));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &Map[i][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visit[i][j]) {
				visit[i][j] = 1;
				if (Map[i][j] == 1) {
					cnt = 0;
					DFS(i, j);
					cnts.push_back(cnt);
				}
			}
		}
	}

	sort(cnts.begin(), cnts.end());
	cout << cnts.size() << endl;
	for (int i = 0; i < cnts.size(); i++) cout << cnts[i] << endl;

	return 0;
}

//sort를 쓰려면 #include <algorithm>하기...