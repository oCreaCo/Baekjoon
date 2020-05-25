#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, v, a, b, now, togo;
int** arr;

int visit[1005];

void DFS(int start) {
	cout << start + 1 << " ";
	visit[start] = 1;
	for (int i = 0; i < n; i++) {
		if (arr[start][i] && !visit[i]) DFS(i);
	}
}

void BFS() {
	queue<int> q;
	now = v - 1;
	for (int i = 0; i < 1005; i++) visit[i] = 0;
	q.push(now);
	visit[now] = 1;

	while (!q.empty())
	{
		now = q.front();
		for (int i = 0; i < n; i++) {
			if (arr[now][i]) {
				togo = i;
				if (!visit[togo]) {
					visit[togo] = 1;
					q.push(togo);
				}
			}
		}
		cout << q.front() + 1 << " ";
		q.pop();
	}
}

int main() {

	cin >> n >> m >> v;

	arr = new int*[n]; 
	for (int i = 0; i < n; ++i) {
		arr[i] = new int[n];
		memset(arr[i], 0, sizeof(int)*(n));
	}

	for (int i = 0; i < m; i++) {//인접행렬
		cin >> a >> b;
		arr[a - 1][b - 1] = 1;
		arr[b - 1][a - 1] = 1;
	}

	now = v;
	DFS(now - 1);
	cout << endl;
	BFS();
	cout << endl;

	return 0;
}

// dfs, bfs의 기본. 앞으로도 열시미 하자

