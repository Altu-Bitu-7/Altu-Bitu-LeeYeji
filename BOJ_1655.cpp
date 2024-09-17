#include <iostream>
#include <queue>

using namespace std;

// 수 비교해서 둘 중 하나의 큐에 넣기
void getNums(int x, priority_queue<int>& q1, priority_queue<int, vector<int>, greater<>>& q2) {
	if (q2.top() >= x) {
		q1.push(x);
	}
	else {
		q1.push(q2.top());
		q2.pop();
		q2.push(x);
	}
}


// 큐의 크기가 하나 이상 차이나지 않도록 해주는 메서드
void makeQueueBalanced(priority_queue<int>& q1, priority_queue<int, vector<int>, greater<>>& q2) {
	if (q1.size() + 1 < q2.size()) {
		q1.push(q2.top());
		q2.pop();
	}
	else if (q1.size() > q2.size() + 1) {
		q2.push(q1.top());
		q1.pop();
	}

	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> q1;
	// 중간값은 q1의 top
	priority_queue<int, vector<int>, greater<>> q2;

	int n; int x;
	cin >> n;

	// 첫 입력에 대한 작업
	cin >> x;
	q2.push(x);
	cout << q2.top() << "\n";

	for (int i = 1; i < n; i++) {
		cin >> x;
		getNums(x, q1, q2);
		
		makeQueueBalanced(q1, q2);
		cout << q1.top() << "\n";
	}

	return 0;
}