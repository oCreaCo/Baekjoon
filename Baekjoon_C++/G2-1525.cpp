#include <iostream>
#include <queue>

using namespace std;

int arr[9];
int visited[9] = { 0 };
int zero;
int dir[4] = {1, -1, 3, -3};

void Swap(int first, int second)
{
    int tmp = arr[second];
    arr[second] = arr[first];
    arr[first] = tmp;
}

int BFS()
{
    int n, nn;
    queue<int> q;
    visited[zero] = 1;
    q.push(zero);

    while(!q.empty())
    {
        n = q.front();
        
        if (n == 8) return visited[n];

        for (int i = 0; i < 4; i++)
        {
            nn = n + dir[i];

            if (nn < 0 || nn >= 9) continue;

            if (arr[nn] == n + 1)
            {
                visited[nn] = visited[n] + 1;
                Swap(n, nn);
                q.push(nn);
            }
        }

        q.pop();
    }

    return 0;
}

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        int tmp;
        cin >> tmp;
        if (tmp == 0)
        {
            zero = i;
        }
        arr[i] = tmp;
    }

    cout << BFS() - 1 << endl;

    return 0;
}