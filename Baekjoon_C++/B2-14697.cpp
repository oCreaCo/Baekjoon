#include <iostream>

using namespace std;

int main(void)
{
    int a, b, c, e, f, g, i, j, k, n;
    int flag = 0;
    
    cin >> e >> f >> g >> n;

    a = (n-1)/e;
    b = (n-1)/f;
    c = (n-1)/g;

    for (i = 0; i <= a+1; i++)
    {
        for (j = 0; j <= b+1; j++)
        {
            for (k = 0; k <= c+1; k++)
            {
                if ((i*e + j*f + k*g) == n) 
                {
                    flag = 1;
                    goto broke;
                }
            }
        }
    }
broke:
    cout << flag << endl;

    return 0;
}