#include <iostream>
#include <stack>

using namespace std;

char cs[100][100];
int visited[100][100] = { 0 };

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int DFS(int n, int x, int y)
{
    int cx, cy, nx, ny;
    stack<pair<int, int>> s;
    s.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!s.empty())
    {
        cx = s.top().first;
        cy = s.top().second;
        s.pop();

        for (int i = 0; i < 4; i++)
        {
            nx = cx + dx[i];
            ny = cy + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

            if (cs[nx][ny] == cs[cx][cy] && !visited[nx][ny])
            {
                s.push(make_pair(cx, cy));
                s.push(make_pair(nx, ny));
                visited[nx][ny] = 1;
                break;
            }
        }
    }

    return 1;
}

int main(void)
{
    int n, cnt = 0, cnt2 = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> cs[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0) cnt += DFS(n, i, j);
        }
    }

    cout << cnt << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
            if (cs[i][j] == 'G') cs[i][j] = 'R';
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0) cnt2 += DFS(n, i, j);
        }
    }

    cout << cnt2 << endl;

    return 0;
}