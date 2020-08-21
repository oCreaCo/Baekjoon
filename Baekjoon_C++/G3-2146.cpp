#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define MAX 101

int min_len = 2 * MAX;
int n;

int arr[MAX][MAX];
int visited[MAX][MAX];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool CheckUnique(vector<pair<int, int>> v, int x, int y)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].first == x && v[i].second == y) return false;
    }
    return true;
}

vector<pair<int, int>> GetStartingPoints(int sx, int sy)
{
    memset(visited, 0, sizeof(visited));
    int x, y, nx, ny;
    queue<pair<int, int>> q;
    vector<pair<int, int>> tmp;
    visited[sx][sy] = 1;
    q.push(make_pair(sx,sy));

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i =0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (arr[nx][ny] && !visited[nx][ny])
            {
                visited[nx][ny] = 1;
                q.push(make_pair(nx, ny));
            }
            else if (!arr[nx][ny] && CheckUnique(tmp, x, y))
            {
                tmp.push_back(make_pair(x, y));
            }
        }

        q.pop();
    }

    return tmp;
}

void GetMinLength(vector<pair<int, int>> v)
{
    int x, y, nx, ny;
    queue<pair<int, int>> q;
    for (int i = 0; i < v.size(); i++)
    {
        visited[v[i].first][v[i].second] = 1;
        q.push(v[i]);
    }

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i =0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (!visited[nx][ny])
            {
                if (!arr[nx][ny])
                {
                    visited[nx][ny] = visited[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
                else
                {
                    if (min_len > visited[x][y]) min_len = visited[x][y];
                    return;
                }
                
            }
        }

        q.pop();
    }
}

int main(void)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] && !visited[i][j]) GetMinLength(GetStartingPoints(i, j));
        }
    }

    cout << min_len - 1 << endl;

    return 0;
}