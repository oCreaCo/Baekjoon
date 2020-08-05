#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adjList;
int arr[100][100] = { 0 };

void BFS(int start)
{


}

int main(void)
{
    int n;
    cin >> n;

	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		adjList.push_back(tmp);
	}

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjList[i].push_back(j);
            adjList[j].push_back(i);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}