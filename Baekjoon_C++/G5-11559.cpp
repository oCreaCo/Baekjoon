#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

char arr[12][6];
int visited[12][6];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS(int sx, int sy)
{
    int x, y, nx, ny;
    queue<pair<int, int>> q;
    q.push(make_pair(sx, sy));
    visited[sx][sy] = 1;

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;

            if (arr[nx][ny] == arr[x][y] && !visited[nx][ny])
            {
                q.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }

        q.pop();
    }

    return 1;
}

void SetColumn(int col)
{
    int i;
    for (i = 0; i < 12; i++)
    {
        if (arr[col][i] != '.')
        {
            break;
        }
    }

    for (int j = i; j < 12; j++)
    {
        arr[col][j - i] = arr[col][j];
        arr[col][j] = '.';
        if (arr[col][j + 1] == '.') break;
    }
}

int main(void)
{
    int cnt;

    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
        }
    }

    while(true)
    {
        cnt = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 0; i < 12; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] != '.' && !visited[i][j]) cnt += BFS(i ,j);
            }
        }

        if (!cnt) break;

        for (int j = 0; j < 6; j++)
        {
            SetColumn(j);
        }
    }

    cout << cnt << endl;

    return 0;
}
