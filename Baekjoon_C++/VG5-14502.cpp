#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int adjArr[8][8];
int infected[8][8] = { 0 };
vector<pair<int, int>> virus;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int n, tmp;

int BFS(vector<pair<int, int>> starts) 
{
    int x, y, nx, ny, cnt = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < starts.size(); i++)
    {
        infected[starts[i].first][starts[i].second] = 1;
        q.push(starts[i]);
        cnt++;
    }
    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx > n - 1 || ny < 0 || ny > tmp - 1) continue;
            if (!adjArr[nx][ny] && !infected[nx][ny])
            {
                infected[nx][ny] = 1;
                q.push(make_pair(nx, ny));
                cnt++;
            }
        }
    }

    return cnt;
}

int main(void)
{
    int a;
    cin >> n >> tmp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tmp; j++)
        {
            cin >> a;
            adjArr[i][j] = a;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tmp; j++)
        {
            if (adjArr[i][j] == 2) virus.push_back(make_pair(i, j));
        }
    }

    cout << BFS(virus) << endl;

    return 0;
}

//BruteForce