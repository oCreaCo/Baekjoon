#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    vector<vector<int>> nums_List;
    int n = 0;
    
    cin >> n;

    while (n != 0)
    {
        int tmp;
        vector<int> tmp_List;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            tmp_List.push_back(tmp);
        }
        nums_List.push_back(tmp_List);
        cin >> n;
    }

    return 0;
}