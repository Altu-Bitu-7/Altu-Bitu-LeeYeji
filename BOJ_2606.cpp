#include <iostream>
#include <vector>

using namespace std;

void dfs(int here, vector<vector<int>>& adjs, vector<bool>& infected) {
	// 현재 컴퓨터를 감염 처리
	infected[here] = true;

	// 연결된 컴퓨터들을 순회하며 감염되지 않은 컴퓨터를 감염시킴
	for (int i = 0; i < adjs[here].size(); i++) {
		int there = adjs[here][i];
		if (!infected[there]) {
			dfs(there, adjs, infected);
		}
	}

	return;
}

// 감염된 컴퓨터의 갯수를 세는 함수
int countInfected(vector<bool>& infected) {
	int ans = 0;

	for (auto i : infected) {
		if (i) ans++;
	}

	// 최초 감염원인 1번 컴퓨터를 제외하고 반환
	return ans - 1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);	cout.tie(NULL);

	int n; cin >> n;
	int n_of_adjs;	cin >> n_of_adjs;
	
	// 컴퓨터 간 연결 정보를 저장
	vector<vector<int>> adjs(n+1);
	int a, b;
	for (int i = 0; i < n_of_adjs; i++) {
		cin >> a >> b;
		adjs[a].push_back(b);
		adjs[b].push_back(a);
	}

	// 컴퓨터의 감염 상태를 저장하는 벡터
	// 모든 컴퓨터는 처음엔 감염되지 않은 상태
	vector<bool> infected(n + 1, false);

	// 1번 컴퓨터에서 감염 시작
	dfs(1, adjs, infected);

	cout << countInfected(infected) << "\n";

	return 0;
}