#include <iostream>
#include <cstring>

#define MAX 51

using namespace std;

int n, m, nx, ny, ex, ey, max_len = 0;
char arr[MAX][MAX];
int visited[MAX][MAX];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void DFS(char c1, char c2, int x, int y)
{
    arr[x][y] = c2;
    if (max_len < visited[x][y]) 
    {
        max_len = visited[x][y];
        ex = x;
        ey = y;
    }
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

        if (arr[nx][ny] == c1 && !visited[nx][ny])
        {
            visited[nx][ny] = visited[x][y] + 1;
            DFS(c1, c2, nx, ny);
        }
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
                ex = i;
                ey = j;
                DFS('L', 'F', i, j);
                memset(visited, 0, sizeof(visited));
                DFS('F', 'T', ex, ey);
            }
        }
    }

    cout << max_len << endl;

    return 0;
}