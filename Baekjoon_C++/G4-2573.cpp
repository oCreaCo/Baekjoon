#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int arr[301][301];
int visited[301][301];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS(int n, int m, int sx, int sy)
{
    int x, y, nx, ny, zeros = 0;
    queue<pair<int, int>> q;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        zeros = 0;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (!visited[nx][ny])
            {
                if (arr[nx][ny])
                {
                    visited[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                }
                else zeros++;
            }
        }

        arr[x][y] -= zeros;
        if (arr[x][y] < 0) arr[x][y] = 0;

        q.pop();
    }

    return 1;
}

int main(void)
{
    int n, m, years = 0, cnt = 1;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    memset(visited, 0, sizeof(arr));

    while(true)
    {
        memset(visited, 0, sizeof(arr));
        cnt = 0;

        for (int i = 1; i < n - 1; i++)
        {
            for (int j = 1; j < m - 1; j++)
            {
                if (arr[i][j] && !visited[i][j]) cnt += BFS(n, m, i, j);
            }
        }

        if (cnt != 1) break;
        years++;
    }

    if (cnt == 0) years = 0;

    cout << years << endl;

    return 0;
}