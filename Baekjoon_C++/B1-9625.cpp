#include <iostream>

using namespace std;

int arr[45];

int main(void)
{
    arr[0] = 0;
    arr[1] = 1;

    int k;
    cin >> k;

    if (k > 1) for (int i = 2; i <= k; i++) arr[i] = arr[i-2] + arr[i-1];

    cout << arr[k-1] << " " << arr[k] << endl;

    return 0;
}

//B -> BA
//A�� ����: �� ���� B�� ����

//A -> B
//B�� ����: �� ���� A�� ���� + �� ���� B�� ����

//B: �Ǻ���ġ