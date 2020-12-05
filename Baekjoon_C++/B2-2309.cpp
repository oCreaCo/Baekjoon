#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v(9);
int sum, i, j;

void Check()
{
    for (i = 0; i < 8; i++)
    {
        for (j = i+1; j < 9; j++)
        {
            if (sum - v[i] - v[j] == 100) 
            {
                return;
            }
        }
    }
}

int main(void)
{
    for (i = 0; i < 9; i++)
    {
        cin >> v[i];
        sum += v[i];
    }

    sort(v.begin(), v.begin()+9);

    Check();

    for (int k = 8; k >= 0; k--)
    {
        if (k == i || k == j) 
        {
            v.erase(v.begin()+k);
        }
    }

    for (i = 0; i < 7; i++) cout << v[i] << endl;

    return 0;
}