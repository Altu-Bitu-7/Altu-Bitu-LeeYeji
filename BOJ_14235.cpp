#include <iostream>
#include <queue>

using namespace std;

void giveGift(priority_queue<int>& gifts) {
	// 우선 선물이 있는지부터 확인하고 없으면 -1 출력
	if (gifts.empty()) {
		cout << "-1\n";
	}
	// 선물이 있다면 가장 큰 가치의 선물 제공
	else {
		cout << gifts.top() << "\n";
		gifts.pop();
	}

	return;
}

// 정해진 수의 선물들을 입력 받아서 priority_queue에 저장
void chargeGift(int num, priority_queue<int>& gifts) {
	int value;

	while (num--) {
		cin >> value;
		gifts.push(value);
	}
	
	return;
}

// 충전소와 아이들 중 무엇과 접촉했는지 확인해서 메서드로 연결
void visit(int n) {
	priority_queue<int> gifts;

	int x;

	while (n--) {
		cin >> x;
		if (x == 0) {
			giveGift(gifts);
		} else {
			chargeGift(x, gifts);
		}
	}

	return;
}

int main() {
	int n;
	cin >> n;

	visit(n);

	return 0;
}