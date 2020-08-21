#include <iostream>
#include <queue>
#include <cstring>

#define MAX 51

using namespace std;

int n, m, nx, ny, ex, ey, max_len = 0;
char arr[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void BFS(int sx, int sy)
{
    int x, y, nx, ny;
    queue<pair<int, int>> q;
    visited[sx][sy] = 1;
    q.push(make_pair(sx, sy));

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (arr[nx][ny] == 'L' && !visited[nx][ny])
            {
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }

        q.pop();

        if (max_len < visited[x][y]) max_len = visited[x][y];
    }
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'L')
            {
                memset(visited, 0, sizeof(visited));
                BFS(i, j);
            }
        }
    }

    cout << max_len - 1 << endl;

    return 0;
}