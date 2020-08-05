#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100000;

bool visit[MAX];
int m, cnt = 0;

void BFS(int from, int to)
{
    int now, tmp = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(from, 0));
    visit[from] = true;
    while (!q.empty())
    {
        now = q.front().first;
        tmp = q.front().second;

        visit[now] = true;
        q.pop();

        if (now == to) 
        {
            if (m && tmp == m) cnt++;
            else if (!m)
            {
                cnt++;
                m = tmp;
            }
        }

        if (now - 1 >= 0 && !visit[now - 1])
            q.push(make_pair(now - 1, tmp + 1));

        if (now + 1 < MAX && !visit[now + 1])
            q.push(make_pair(now + 1, tmp + 1));

        if (now * 2 < MAX && !visit[now * 2])
            q.push(make_pair(now * 2, tmp + 1));

    }
}

int main(void)
{
    int from, to;
    cin >> from >> to;
    BFS(from, to);

    cout << m << '\n'
         << cnt << endl;

    return 0;
}

//욕밖에안나옴