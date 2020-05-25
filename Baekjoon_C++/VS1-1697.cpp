#include <iostream>
#include <queue>

using namespace std;

#define MAX 100001

int v[MAX] = {0};

int main() {
    int a, b, tmp, cnt = 0;

    cin >> a >> b;

    queue<int> q;
    q.push(a);
    v[a] = 1;
    
    while(!q.empty()) {
        tmp = q.front();

        if(tmp == b) {
            cnt = v[tmp];
            break;
        }

        if (tmp - 1 >= 0 && v[tmp - 1] == 0) {
            v[tmp - 1] = v[tmp] + 1;
            q.push(tmp - 1);
        }
        if (tmp + 1 <= MAX && v[tmp + 1] == 0) {
            v[tmp + 1] = v[tmp] + 1;
            q.push(tmp + 1);
        }
        if (2 * tmp <= MAX && v[2 * tmp] == 0) {
            v[2 * tmp] = v[tmp] + 1;
            q.push(2 * tmp);
        }

        q.pop();
    }

    cout << cnt - 1 << endl;

    return 0;
}

//수학문제같지만 결국 bfs... 길찾기는 거의 bfs라고 보자