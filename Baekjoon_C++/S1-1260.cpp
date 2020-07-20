#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int n, m, v, a, b;
vector<vector<int>> arr;

int visit[1005] = { 0 };

void DFS()
{
	int now = v - 1;
	stack<int> s;
	s.push(now);
	visit[now] = 1;
	cout << now + 1 << " ";
	while(!s.empty())
	{
		now = s.top();
		s.pop();
		for (int i = 0; i < arr[now].size(); i++)
		{
			if (!visit[arr[now][i]])
			{
				cout << arr[now][i] + 1 << " ";
				visit[arr[now][i]] = 1;
				s.push(now);
				s.push(arr[now][i]);
				break;
			}
		}
	}
}

void BFS()
{
	queue<int> q;
	int now = v - 1;
	for (int i = 0; i < 1005; i++) visit[i] = 0;
	q.push(now);
	visit[now] = 1;

	while (!q.empty())
	{
		now = q.front();
		for (int i = 0; i < arr[now].size(); i++)
		{
			if (!visit[arr[now][i]]) 
			{
				visit[arr[now][i]] = 1;
				q.push(arr[now][i]);
			}
		}
		cout << q.front() + 1 << " ";
		q.pop();
	}
}

int main() {

	cin >> n >> m >> v;

	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		arr.push_back(tmp);
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		arr[a - 1].push_back(b - 1);
		arr[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++)
	{
		sort(arr[i].begin(), arr[i].end());
	}

	DFS();
	cout << endl;
	BFS();
	cout << endl;

	return 0;
}

// dfs, bfs의 기본형

