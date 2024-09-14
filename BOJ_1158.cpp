#include <iostream>
#include <queue>

using namespace std;

// 1부터 n까지의 수로 queue 채워주기
void makeQueueFull(queue<int>& q, const int n) {	
	for (int i = 0; i < n; i++)
		q.push(i + 1);
}

queue<int> popKth(queue<int>& q, const int n, const int k) {
	queue<int> yq;
	int cnt;

	for (int i = 0; i < n; i++) {
		// k-1번만큼 숫자 빼서 다시 넣어주고
		for (int j = 0; j < k - 1; j++) {
			cnt = q.front();
			q.pop();
			q.push(cnt);
		}
		// k번째의 값은 다른 큐에 담아주기
		yq.push(q.front());
		q.pop();
	}

	return yq;
}

int main() {

	int n, k;
	cin >> n >> k;

	queue<int> q;

	makeQueueFull(q, n);
	queue<int> yq = popKth(q, n, k);


	cout << "<" << yq.front();
	yq.pop();

	while (!yq.empty()) {
		cout << ", " << yq.front();
		yq.pop();
	}

	cout << ">";

	return 0;
}