#include <iostream>
#include <queue>
#include <vector>

#define INF -300000

using namespace std;

int dist[20005] = { 0 };

vector<pair<int, int>> adjList[30005];
int v, e, s;

void Dijkstra(int start)
{
    int now, next, weight;
    vector<pair<int, int>> tmp;
    dist[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(0, start));

    while(!pq.empty())
    {
        now = pq.top().second;
        pq.pop();
        tmp = adjList[now];

        for (int i = 0; i < tmp.size(); i++)
        {
            next = tmp[i].first;
            weight = -tmp[i].second;
            if (dist[now] + weight > dist[next])
            {
                dist[next] = dist[now] + weight;
                pq.push(make_pair(dist[next], next));
                
            }
        }
    }
}


int main(void)
{
    cin >> v >> e;
    for (int i = 1; i < v + 1; i++)
    {
        dist[i] = INF;
    }
    cin >> s;

    int a, b, w;
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        adjList[a].push_back(make_pair(b, w));
    }

    Dijkstra(s);

    for (int i = 1; i < v + 1; i++) 
    {
        if (dist[i] != INF) cout << -1 * dist[i] << "\n";
        else cout << "INF\n";
    }

    return 0;
}