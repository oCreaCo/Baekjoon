#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

int map[25][25];
int visit[25][25] = { 0 };
vector<int> cnts;
int n, cnt;

void DFS(int i, int j)
{
	int x = i, y = j;
	visit[x][y] = 1;
	stack<pair<int, int>> s;
	s.push(make_pair(x, y));
	pair<int, int> now;

	while(!s.empty())
	{
		now = s.top();
		s.pop();
		x = now.first;
		y = now.second;
		if (x > 0 && map[x - 1][y] && !visit[x - 1][y])
		{
			visit[x - 1][y] = 1;
			s.push(now);
			s.push(make_pair(x - 1, y));
			cnt++;
			continue;
		}
		if (y > 0 && map[x][y - 1] && !visit[x][y - 1])
		{
			visit[x][y - 1] = 1;
			s.push(now);
			s.push(make_pair(x, y - 1));
			cnt++;
			continue;
		}
		if (x < n - 1 && map[x + 1][y] && !visit[x + 1][y])
		{
			visit[x + 1][y] = 1;
			s.push(now);
			s.push(make_pair(x + 1, y));
			cnt++;
			continue;
		}
		if (y < n - 1 && map[x][y + 1] && !visit[x][y + 1])
		{
			visit[x][y + 1] = 1;
			s.push(now);
			s.push(make_pair(x, y + 1));
			cnt++;
			continue;
		}
	}
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%1d", &map[i][j]);
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] && !visit[i][j])
			{
				cnt = 1;
				DFS(i, j);
				cnts.push_back(cnt);
			}
		}
	}

	cout << cnts.size() << endl;
	for (int i = 0; i < cnts.size(); i++) cout << cnts[i] << endl;

	return 0;
}