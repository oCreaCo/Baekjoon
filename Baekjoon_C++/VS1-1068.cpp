#include <iostream>
#include <vector>
#include <queue>

#define max_int 51
using namespace std;

//시간 복잡도: O(n)
//공간 복잡도: O(n)
//사용한 알고리즘: BFS
//사용한 자료구조: 인접 리스트


int n, num, root_node, result = 0;
// 그래프를 저장할 인접 리스트
vector<int> v[max_int];

// 정점 방문 여부를 저장할 배열
bool check[max_int];

// BFS로 그래프를 탐색합니다.
void bfs(int start) {
	check[start] = true;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		// 자식의 숫자를 계산할 변수
		int child_cnt = 0;
		for (int i = 0; i<v[node].size(); i++) {
			int next = v[node][i];
			if (!check[next]) {
				child_cnt++;
				check[next] = true;
				q.push(next);
			}
		}
		// 자식이 없으면 단말 노드 계수를 1 증가 시킵니다.
		if (child_cnt == 0) {
			result++;
		}
	}
}

int main() {
	// 1. 입력
	scanf("%d", &n);
	for (int i = 0; i<n; i++) {
		scanf("%d", &num);
		// 1) 인접 리스트를 사용해서 양방향 그래프로 트리를 만들어줍니다.
		if (num != -1) {
			v[num].push_back(i);
			v[i].push_back(num);

		}
		// 2) 루트 노드일 경우 표시합니다.
		else {
			root_node = i;
		}
	}

	// 2. 지울 노드 표시
	scanf("%d", &num);
	check[num] = true;

	// 3. 만약 지워진 노드가 루트 노드가 아니라면 탐색을 시작합니다.
	if (!check[root_node]) bfs(root_node);

	// 4. 출력
	printf("%d\n", result);
}

//하...