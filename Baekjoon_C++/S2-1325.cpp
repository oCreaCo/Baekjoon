#include <iostream>
#include <stack>
#include <vector>
#include <cstring>

using namespace std;

int n, m, max_num = 0;
vector<vector<int>> adjList;
vector<int> ans;
int visited[10001];

int DFS(int start)
{
    int cnt = 1, now, next;
    stack<int> s;
    s.push(start);
    visited[start] = 1;

    while(!s.empty())
    {
        now = s.top();
        s.pop();
        for (int i = 0; i < adjList[now].size(); i++)
        {
            next = adjList[now][i];
            if (!visited[next])
            {
                visited[next] = 1;
                s.push(now);
                s.push(next);
                cnt++;
                break;
            }
        }
    }

    return cnt;
}

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i ++)
    {
        vector<int> tmp;
        adjList.push_back(tmp);
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjList[b-1].push_back(a-1);
    }

    int cnt;
    for (int i = 0; i < n; i ++)
    {
        memset(visited, 0, sizeof(visited));
        cnt = DFS(i);
        if (cnt > max_num)
        {
            max_num = cnt;
            ans.clear();
            ans.push_back(i+1);
        }
        else if (cnt == max_num) ans.push_back(i+1);
    }

    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';
    cout << endl;

    return 0;
}