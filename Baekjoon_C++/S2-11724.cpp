#include <iostream>
#include <queue>

using namespace std;


int n, m;
vector<vector<int>> adjList;
int visit[1000] = { 0 };

void BFS(int start)
{
    int now = start;
    queue<int> q;
    q.push(now);
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for (int i = 0; i < adjList[now].size(); i++)
        {
            if (!visit[adjList[now][i]])
            {
                visit[adjList[now][i]] = 1;
                q.push(adjList[now][i]);
            }
        }
    }
}

int main(void)
{
    int cnt = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp;
        adjList.push_back(tmp);
    }
    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        adjList[a - 1].push_back(b - 1);
        adjList[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
    {
        if(!visit[i])
        {
            BFS(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}