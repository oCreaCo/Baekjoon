#include <iostream>

using namespace std;

int arr[21] = { 0 };

int main(void)
{
    arr[0] = 0;
    arr[1] = 1;

    int n;
    cin >> n;
    
    if (n > 1)
    {
        for (int i = 2; i <= n; i++)
        {
            arr[i] = arr[i-2] + arr[i-1];
        }
    }
    cout << arr[n] << endl;

    return 0;
}