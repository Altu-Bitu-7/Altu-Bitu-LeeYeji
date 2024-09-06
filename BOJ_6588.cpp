#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

const int MAX = 1000000;

void checkPrime(vector<bool>& is_prime) {
	// 0과 1은 소수가 아니므로 먼저 제거
	is_prime[0] = is_prime[1] = false;

	//2~제곱근 n까지 검사
	for (int i = 2; i * i <= MAX; i++)
		if (is_prime[i]) {	// i가 소수라면
			// i * i 이전의 수들은 이미 지워진 상태이므로 j = i * i로 시작
			for (int j = i * i; j <= MAX; j += i) {
				is_prime[j] = false;	// i의 배수들 제거
			}
		}
}

// 시간 복잡도 n/2 ?
tuple<int, int, int> primeAdd(int n, vector<bool>& is_prime) {
	for (int i = 2; i <= n / 2; i++) {
		if (is_prime[i])
			if (is_prime[n - i])
				return make_tuple(n, i, n - i);
	}

	return make_tuple(0, 0, 0);
}

int main() {
	int n;
	vector<tuple<int, int, int>> result;

	// 소수 여부  판단
	vector<bool> is_prime(MAX + 1, true);
	checkPrime(is_prime);

	while (true) {
		cin >> n;
		if (n == 0) break; 

		tuple<int, int, int> value = primeAdd(n, is_prime);

		result.push_back(value);
	}

	for (size_t i = 0; i < result.size(); i++) {
		if (get<0>(result[i]) == 0) {
			cout << "Goldbach's conjecture is wrong.\n";
		}
		cout << get<0>(result[i]) << " = " << get<1>(result[i]) << " + " << get<2>(result[i]) << "\n";
	}

	return 0;
}