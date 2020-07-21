#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct coord
{
    int x, y, z;
};

int map[1000][1000];
int dist[1000][1000][2] = { 0 };
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS(int n, int m)
{
    dist[0][0][0] = 1;
    int x = 0, y = 0, z = 0;
    int nx, ny;
    queue<coord> q;
    coord now = {0, 0, 0};
    q.push(now);

    while(!q.empty())
    {
        now = q.front();
        q.pop();
        x = now.x;
        y = now.y;
        z = now.z;

        for (int i = 0; i < 4; i++)
        {
            if (x == n - 1 && y == m - 1) return dist[x][y][z];
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (dist[nx][ny][z]) continue;
            if (map[nx][ny] == 0)
            {
                dist[nx][ny][z] = dist[x][y][z] + 1;
                q.push({nx, ny, z});
            }
            else if (map[nx][ny] == 1 && z == 0)
            {
                dist[nx][ny][1] = dist[x][y][z] + 1;
                q.push({nx, ny, 1});
            }
        }
    }
    return -1;
}

int main(void)
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &map[i][j]);
        }
    }

    cout << BFS(n, m) << endl;

    return 0;
}