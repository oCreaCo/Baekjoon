#include <iostream>

using namespace std;

long long arr[80];

int main(void)
{
    arr[0] = 1;
    arr[1] = 1;

    int n;
    cin >> n;

    if (n > 2) for (int i = 2; i < n; i++) arr[i] = arr[i-2] + arr[i-1];

    cout << 4 * arr[n-1] + 2 * arr[n-2] << endl;

    return 0;
}