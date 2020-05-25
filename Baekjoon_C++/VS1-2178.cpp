#include <iostream>
#include <queue>
#include <utility>
#include <string>

using namespace std;

int x, y;

int arr[100][100] = {0, 0};
int check[100][100] = {0, 0};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void BFS(int i, int j) {
    check[i][j]++;

    queue<pair<int, int>> q;
    q.push(make_pair(i, j));

    while(!q.empty()) {
        int xI = q.front().first;
        int yI = q.front().second;

        for(int k = 0; k < 4; k++) {
            int newX = 0, newY = 0;

            newX = xI + dx[k];
            newY = yI + dy[k];

            if (newX >= 0 && newX < x && newY >= 0 && newY < y && arr[newX][newY] == 1 && check[newX][newY] == 0) {
                check[newX][newY] = check[xI][yI] + 1;
                q.push(make_pair(newX, newY));
            }
        }

        q.pop();
    }
}

int main() {

    cin >> x >> y;

    for (int i = 0; i < x; i++) {
        string temp;
        cin >> temp;
        
        for (int j = 0; j < y; j++) {
            arr[i][j] = temp[j] - 48;
        }
        
    }

    BFS(0, 0);
    cout << check[x - 1][y - 1];

   return 0;
}

//check배열에서 단순히 0 1로 체크를 한게 아니라 거리값을 넣어서 한번에 계산했다
//코드 예술이다 시발 열심히 살자