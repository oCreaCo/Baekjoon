#include <iostream>
#include <bitset>

using namespace std;

int main(void)
{
    unsigned int stick = 0x0040;
    int x, cnt = 1;
    cin >> x;

    while(stick != x)
    {
        if (stick > x) stick = stick >> 1;
        else 
        {
            x = x - stick;
            cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}
