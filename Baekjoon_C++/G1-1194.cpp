#include <iostream>
#include <bitset>
#include <queue>

using namespace std;

int n = 0, m = 0, sx = 0, sy = 0;

char arr[55][55];
int visited[55][55][0x0040] = { 0 };

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Data
{
    int x;
    int y;
    unsigned int bitmask;
};


int BFS()
{
    int x, y, nx, ny;
    unsigned int bitmask = 0x0000, nBitmask;
    Data now;
    queue<Data> q;
    visited[sx][sy][bitmask] = 1;
    now = {sx, sy, bitmask};
    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        x = now.x;
        y = now.y;
        bitmask = now.bitmask;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (arr[nx][ny] != '#' && !visited[nx][ny][bitmask])
            {
                if (arr[nx][ny] == '.')
                {
                    visited[nx][ny][bitmask] = visited[x][y][bitmask] + 1;
                    q.push({nx, ny, bitmask});
                }
                else if (arr[nx][ny] == '1') return visited[x][y][bitmask];
                else
                {
                    if (int(arr[nx][ny]) > 90)
                    {
                        nBitmask = bitmask | (1 << int(arr[nx][ny]) - 97);
                        visited[nx][ny][nBitmask] = visited[x][y][bitmask] + 1;
                        q.push({nx, ny, nBitmask});
                    }
                    else if ((bitmask & (1 << int(arr[nx][ny]) - 65)) != 0)
                    {
                        visited[nx][ny][bitmask] = visited[x][y][bitmask] + 1;
                        q.push({nx, ny, bitmask});
                    }
                }
            }
        }

        q.pop();
    }

    return -1;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == '0')
            {
                sx = i;
                sy = j;
                arr[i][j] = '.';
            }
        }
    }

    cout << BFS() << endl;

    return 0;
}