#include <iostream>

using namespace std;

int main(void)
{
    int a, n, flag = -1;
    cin >> n;
    a = n/5;

    for (int i = a; i >= 0; i--)
    {
        if ((n - i*5)%3 == 0)
        {
            flag = i + (n - i*5)/3;
            goto broke;
        }
    }

broke:
cout << flag << endl;

    return 0;
}