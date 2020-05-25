#include <iostream>
#include <vector>
#include <stack>
#include <string.h>
#include <algorithm>

using namespace std;

int n, w, h, cbgs, cnt = 0;
int** visit;
int** Map;
stack<pair<int, int>> s;
vector<int> cnts;

void DFS(int i, int j) {
	int a = i, b = j, added;

	while (!s.empty()) {
		s.pop();
		visit[a][b] = 1;
		added = 0;
		if (a > 0 && Map[a - 1][b] == 1 && visit[a - 1][b] == 0) {
			s.push(make_pair(a - 1, b));
			added = 1;
		}
		if (b < h - 1 && Map[a][b + 1] == 1 && visit[a][b + 1] == 0) {
			s.push(make_pair(a, b + 1));
			added = 1;
		}
		if (a < w - 1 && Map[a + 1][b] == 1 && visit[a + 1][b] == 0) {
			s.push(make_pair(a + 1, b));
			added = 1;
		}
		if (b > 0 && Map[a][b - 1] == 1 && visit[a][b - 1] == 0) {
			s.push(make_pair(a, b - 1));
			added = 1;
		}

		if (!s.empty()) {
			a = s.top().first;
			b = s.top().second;
			if (added) s.push(make_pair(0, 0));
		}
	}

	cnt++;
}

int main() {

	cin >> n;
	for (int tmp = 0; tmp < n; tmp++) {
		cin >> w >> h >> cbgs;

		Map = new int*[w];
		for (int i = 0; i < w; i++) {
			Map[i] = new int[h];
			memset(Map[i], 0, sizeof(int)*(h));
		}
		visit = new int*[w];
		for (int i = 0; i < w; i++) {
			visit[i] = new int[h];
			memset(visit[i], 0, sizeof(int)*(h));
		}

		int a, b;
		for (int i = 0; i < cbgs; i++) {
			cin >> a >> b;
			Map[a][b] = 1;
		}

		cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++) {
				if (!visit[i][j]) {
					if (Map[i][j] == 1) {
						s.push(make_pair(i, j));
						DFS(i, j);
					} else visit[i][j] = 1;
				}
			}
		}
		cnts.push_back(cnt);
	}
	for (int i = 0; i < cnts.size(); i++) cout << cnts[i] << endl;

	return 0;
}

//재귀는 메모리가 너무 많이 든다... 스택을 쓸 수 있도록 하자...ㅠㅠ