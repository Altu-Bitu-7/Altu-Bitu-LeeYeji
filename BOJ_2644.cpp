#include <iostream>
#include <vector>

using namespace std;

int x, y;

int dfs(int here, vector<vector<int>>& adjs, vector<bool>& visited) {
	visited[here] = true;

	// base case: 목표로 하는 사람에 도달
	if (here == y) {
		return 0;
	}

	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];
		if (!visited[there]) {
			int result = dfs(there, adjs, visited);

			// result가 -1이 아니면, 즉 촌수를 찾았으면 +1하여 반환
			if (result != -1) {
				return result + 1;
			}
		}
	}

	// 여기까지 왔다는 것은 경로를 찾지 못했다는 의미이므로 -1 반환
	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n; cin >> n;
	cin >> x; cin >> y;
	int m;	cin >> m;
	
	vector<vector<int>> adjs(n + 1);
	int a, b;

	// 부모 자식 관계를 입력받아 인접 리스트에 추가
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}

	// 방문 여부를 저장하는 벡터
	vector<bool> visited(n + 1, false);

	cout << dfs(x, adjs, visited) << "\n";

	return 0;
}