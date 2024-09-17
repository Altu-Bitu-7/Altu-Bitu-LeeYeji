#include <iostream>
#include <queue>

using namespace std;

typedef long long ll;

// min_heap을 n 사이즈로 유지하며 n^2개의 입력을 받는 메서드
void getInput(const int n, priority_queue<ll, vector<ll>, greater<ll>>& pq) {
	ll num;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			pq.push(num);

			// 크기가 n을 넘으면 가장 작은 값 제거
			if (pq.size() > n)
				pq.pop();
		}
	}

	return;
}

// 가장 마지막에 위치한 n번째로 큰 수를 리턴하는 메서드
int nth(int n, priority_queue<ll>& pq) {
	while (--n) {
		pq.pop();
	}

	return pq.top();
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	priority_queue<ll, vector<ll>, greater<ll>> min_heap;
	getInput(n, min_heap);

	cout << min_heap.top() << "\n";

	return 0;
}