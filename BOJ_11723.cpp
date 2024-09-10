#include <iostream>

using namespace std;

const int MAX = 20;

int toBinary(int x) {
	// 이진수로 1 정의
	int n = 0b1;	
	
	return n << x-1;
}

// x 번째 비트 확인
int check(int x, int bit_mask) {
	/*
	 check 3 -> check 0b100
	 <TURE CASE> 0b100 >> 10 >> 1 TRUE
	 <FALSE CASE> 0b000 >> 00 >> 0 false
	*/

	// 1 혹은 0만 남을 수 있게 RightShift 하고 2로 나눴을 때 나머지 확인
	if ((bit_mask >> (x - 1)) % 2 == 1)
		return 1;
	return 0;
}

// x 번째 비트 1로 설정
void add(int x, int& bit_mask) {
	bit_mask |= toBinary(x);
	return;
}

// x 번째 비트 0으로 설정
void remove(int x, int& bit_mask) {
	// 
	if (check(x, bit_mask)) {
		bit_mask = bit_mask xor toBinary(x);
		return;
	}
	return;
}

// x 번째 비트 반전
void toggle(int x, int& bit_mask) {
	bit_mask = bit_mask xor toBinary(x);
	return;
}

// 모든 비트를 0으로 설정
void empty(int& bit_mask) {
	bit_mask = 0;
}

// 모든 비트를 1로 설정 (즉, {1, 2, ..., 20})
void all(int& bit_mask) {
	/*
	1 << MAX의 이진수: 100000000000000000000
	1을 빼면: 011111111111111111111
	=> 즉, 20개의 비트가 모두 1이 됨
	*/
	bit_mask = (1 << MAX) - 1;
}

void control(int m, int& bit_mask) {
	string fun;
	int x;

	for (int i = 0; i < m; i++) {
		cin >> fun;

		// x 입력을 받지 않는 두 연산만 먼저 수행
		if (fun == "all") {
			all(bit_mask);
			continue;
		}
		else if (fun == "empty") {
			empty(bit_mask);
			continue;
		}

		cin >> x;

		if (fun == "add") {
			add(x, bit_mask);
		}
		else if (fun == "remove") {
			remove(x, bit_mask);
		}
		else if (fun == "check") {
			cout << check(x, bit_mask) << "\n";
		}
		else if (fun == "toggle") {
			toggle(x, bit_mask);
		}
	}

	return;
}

int main() {
	// 입출력 성능 향상
	ios::sync_with_stdio(false); 
	cin.tie(nullptr); cout.tie(nullptr);

	long m;
	int bit_mask = 0;

	cin >> m;

	control(m, bit_mask);

	return 0;
}