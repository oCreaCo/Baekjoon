#include <iostream>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

char arr[12][6];
int visited[12][6];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS(int sx, int sy, char c)
{
    int x, y, nx, ny, cnt = 0;
    queue<pair<int, int>> q;
    vector<pair<int, int>> v;
    q.push(make_pair(sx, sy));
    v.push_back(make_pair(sx, sy));
    visited[sx][sy] = 1;

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        cnt++;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6) continue;

            if (arr[nx][ny] == c && !visited[nx][ny])
            {
                q.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny));
                visited[nx][ny] = 1;
            }
        }

        q.pop();
    }
    
    if (cnt > 3) 
    {
        for (int i = 0; i < v.size(); i++)
        {
            arr[v[i].first][v[i].second] = '.';
        }
        return 1;
    }
    else return 0;
}

void SetColumn(int col)
{
    int i, j, sub;
    for (i = 0; i < 12; i++)
    {
        if (arr[i][col] == '.') break;
    }
    
    for (j = i + 1; j < 12; j++)
    {
        if (arr[j][col] != '.') break;
    }
    
    if (j == 12) return;
    
    sub = j - i;
    while(arr[j][col] != '.')
    {
        arr[j - sub][col] = arr[j][col];
        arr[j][col] = '.';
        j++;
    }
}

int main(void)
{
    int tmp, cnt = 0;

    for (int i = 11; i > -1; i--)
    {
        for (int j = 0; j < 6; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == ',') visited[i][j] = 1;
        }
    }

    while(true)
    {
        tmp = 0;
        memset(visited, 0, sizeof(visited));
        for (int i = 11; i > -1; i--)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr[i][j] != '.' && !visited[i][j]) tmp += BFS(i ,j, arr[i][j]);
            }
        }

        if (tmp == 0) break;

        for (int j = 0; j < 6; j++)
        {
            SetColumn(j);
        }

        cnt++;
    }

    cout << cnt << endl;

    return 0;
}
