#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int n, m, a, b, now = 1, togo, c = 0;

int visit[105];
vector<int> adj[101];

void BFS() {
	queue<int> q;
	for (int i = 0; i < 105; i++) visit[i] = 0;
	q.push(now);
	visit[now] = 1;

	while (!q.empty())
	{
		now = q.front();
		for (int i = 0; i < adj[now].size(); i++) {
			togo = adj[now][i];
			if (!visit[togo]) {
				visit[togo] = 1;
				c++;
				q.push(togo);
			}
		}
		q.pop();
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < m; i++) {//��������Ʈ
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	BFS();
	cout << c << endl;

	return 0;
}

//ũ�� ���Ѵ� �� ������ ���� �Ф�