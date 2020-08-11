#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

pair<int, int> s;
vector<pair<int, int>> waters;

char arr[51][51];
int visited[51][51];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int BFS()
{
    int x, y, nx, ny;
    queue<pair<int, int>> q;
    for (int i = 0; i < waters.size(); i++) q.push(waters[i]);
    q.push(s);

    while(!q.empty())
    {
        x = q.front().first;
        y = q.front().second;

        for (int i = 0; i < 4; i++)
        {
            nx = x + dx[i];
            ny = y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

            if (arr[nx][ny] == '.' && !visited[nx][ny])
            {
                arr[nx][ny] = arr[x][y];
                visited[nx][ny] = visited[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
            else if (arr[x][y] == 'S' && arr[nx][ny] == 'D') return visited[x][y];
        }

        q.pop();
    }

    return 0;
}

int main(void)
{
    char c;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c;
            if (c == '*') 
            {
                waters.push_back(make_pair(i, j));
                visited[i][j] = 1;
            }
            else if (c == 'X') visited[i][j] = 1;
            else if (c == 'S') 
            {
                s = make_pair(i, j);
                visited[i][j] = 1;
            }
            arr[i][j] = c;
        }
    }

    int cnt = BFS();

    if (cnt > 0) cout << cnt << endl;
    else cout << "KAKTUS" << endl;

    return 0;
}