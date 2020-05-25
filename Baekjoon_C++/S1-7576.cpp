#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int x, y, xI, yI, newX, newY;
int tomatos[1000][1000] = {0, 0};

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int BFS(vector<pair<int, int>> sTs) {
    int days = 0;
    queue<pair<int, int>> q;

    for (int i = 0; i < sTs.size(); i++) {
        q.push(sTs[i]);
    }

    bool vEmpty = false;
    while(!q.empty()) {
                yI = q.front().first;
                xI = q.front().second;
                for (int dirI = 0; dirI < 4; dirI++) {
                    newX = xI + dx[dirI];
                    newY = yI + dy[dirI];

                    if (newX >= 0 && newX < x && newY >= 0 && newY < y && tomatos[newY][newX] == 0) {
                        tomatos[newY][newX] = tomatos[yI][xI] + 1;
                        q.push(make_pair(newY, newX));
                    }
                }
                q.pop();
                if (q.empty()) {
                    days = tomatos[yI][xI] - 1;
                }
    }

    return days;
}

int main() {
    int days;
    vector<pair<int, int>> startingTomatos;

    cin >> x >> y;

    for (int j = 0; j < y; j++) {
        for (int i = 0; i < x; i++) {
            cin >> tomatos[j][i];
            if (tomatos[j][i] == 1) startingTomatos.push_back(make_pair(j ,i));
        }
    }

    if (startingTomatos.size() == 0) {
        days = -1;
    } else {
        days = BFS(startingTomatos);

        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                if (tomatos[j][i] == 0) {
                    days = -1;
                    break;
                }
            }
        }
    }

    cout << days << endl;

    return 0;
}

//2중큐는 메모리를 많이 먹네... 가급적이면 큐는 하나 쓰고 인덱스로 구분하던가 다른 방법으로 구현하도록 하자