#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int x, y, z, xI, yI, zI, newX, newY, newZ;
int tomatos[100][100][100] = {0, 0, 0};

int dx[6] = {0, 1, 0, -1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

int BFS(vector<vector<int>> sTs) {
    int days = 0;
    queue<vector<int>> q;

    for (int i = 0; i < sTs.size(); i++) {
        q.push(sTs[i]);
    }

    bool vEmpty = false;
    while(!q.empty()) {
        yI = q.front()[0];
        xI = q.front()[1];
        zI = q.front()[2];
        
        for (int dirI = 0; dirI < 6; dirI++) {
            newX = xI + dx[dirI];
            newY = yI + dy[dirI];
            newZ = zI + dz[dirI];

            if (newX >= 0 && newX < x && newY >= 0 && newY < y && newZ >= 0 && newZ < z && tomatos[newY][newX][newZ] == 0) {
                tomatos[newY][newX][newZ] = tomatos[yI][xI][zI] + 1;
                vector<int> v = {newY, newX, newZ};
                q.push(v);
            }
        }
        q.pop();
        if (q.empty()) {
            days = tomatos[yI][xI][zI] - 1;
        }
    }

    return days;
}

int main() {
    int days;
    vector<vector<int>> startingTomatos;

    cin >> x >> y >> z;

    for (int k = 0; k < z; k++) {
        for (int j = 0; j < y; j++) {
            for (int i = 0; i < x; i++) {
                cin >> tomatos[j][i][k];
                if (tomatos[j][i][k] == 1) {
                    vector<int> v = {j, i, k};
                    startingTomatos.push_back(v);
                }
            }
        }
    }

    if (startingTomatos.size() == 0) {
        days = -1;
    } else {
        days = BFS(startingTomatos);

        for (int k = 0; k < z; k++) {
            for (int j = 0; j < y; j++) {
                for (int i = 0; i < x; i++) {
                    if (tomatos[j][i][k] == 0) {
                        days = -1;
                        break;
                   }
                }
            }
        }
    }

    cout << days << endl;

    return 0;
}

//아이고 시발....