#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;
vector<int> nums;    // 입력 받은 수들
vector<int> sequence; // 수열을 저장할 벡터

// 수열 출력 함수
void printSequence() {
	for (int i = 0; i < m; i++) {
		cout << sequence[i] << " ";  // 저장된 수열 출력
	}
	cout << "\n";
}

void backtrack(int depth) {
	// base case: 모두 뽑은 경우 출력
	if (depth == m) {
		printSequence();
		return;
	}

	for (int i = 0; i < nums.size(); ++i) {
		sequence[depth] = nums[i];
		backtrack(depth + 1);  // 재귀 호출로 다음 수 선택
	}
}

int main() {
	cin >> n >> m;

	nums.resize(n);  // nums 크기 설정
	sequence.resize(m);  // 수열 크기 설정

	// nums 입력 받기
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	// 중복 제거 및 정렬
	sort(nums.begin(), nums.end());
	nums.erase(unique(nums.begin(), nums.end()), nums.end());

	backtrack(0); 

	return 0;
}
