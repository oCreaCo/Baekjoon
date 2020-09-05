#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int arr[9];
int visited[9] = { 0 };
int zero;
int dir[4] = {1, -1, 3, -3};

void Swap(int* tmpArr, int first, int second)
{
    int tmp = tmpArr[second];
    tmpArr[second] = tmpArr[first];
    tmpArr[first] = tmp;
}

int BFS(int s)
{
    memset(visited, 0, sizeof(visited));
    int* tmpArr = GetTmpArr();
    int n, nn;
    queue<int> q;
    visited[s] = 1;
    q.push(s);

    while(!q.empty())
    {
        n = q.front();
        
        if (n == 8) return visited[n];

        for (int i = 0; i < 4; i++)
        {
            nn = n + dir[i];

            if (nn < 0 || nn >= 9) continue;

            if (tmpArr[nn] == n + 1)
            {
                visited[nn] = visited[n] + 1;
                Swap(tmpArr, n, nn);
                q.push(nn);
            }
        }

        q.pop();
    }

    return 0;
}

int* GetTmpArr()
{
    int tmpArr[9];
    for (int i = 0; i < 9; i++) tmpArr[i] = arr[i];
    return tmpArr;
}

int main(void)
{
    for (int i = 0; i < 9; i++)
    {
        int tmp;
        cin >> arr[i];
    }

    for (int i = 0; i < 9; i++)
    {
        BFS(i);
    }

    return 0;
}