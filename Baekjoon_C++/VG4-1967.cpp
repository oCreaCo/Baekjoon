#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int n;
int visited[10002] = { 0 };
vector<pair<int, int>> node[10002];

int radius = 0; //���� ����
int end_point = 0; //������ �ش��ϴ� ����
void dfs(int point, int length) {
	if (visited[point] == 1) return;

	visited[point] = 1;
	if (radius < length) {
		radius = length;
		end_point = point;
	}

	for (int i = 0; i < node[point].size(); i++) dfs(node[point][i].first, length + node[point][i].second);
}

int main() {

	cin >> n;

	int parent, child, length;
	for (int i = 0; i<n - 1; i++) {
		scanf("%d %d %d", &parent, &child, &length);
		node[parent].push_back(make_pair(child, length));
		node[child].push_back(make_pair(parent, length));
	}

	dfs(1, 0);

	radius = 0;
	memset(visited, 0, sizeof(visited));

	dfs(end_point, 0);
	cout << radius << endl;

	return 0;
}

//�� ��Ƴ�
//Ʈ�������� ������ ������ ���� Ǫ�¹�������
//dfs�� 2���̳� ����
//Ʈ����� �������� ���� Ʈ�������� �������� ����