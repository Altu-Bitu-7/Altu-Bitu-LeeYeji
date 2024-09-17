#include <iostream>
#include <vector>

using namespace std;

// count 하기 전 vector를 모두 0으로 초기화하는 메서드
void reset(vector<int>& alpha) {
	for (int i = 0; i < alpha.size(); i++) {
		alpha[i] = 0;
	}
}

// 기준이 될 첫 번째 string의 알파벳 수를 세는 메서드
void count(string str, vector<int>& alpha) {
	for (auto ch : str) {
		int idx = ch - 'A';
		alpha[idx]++;
	}

	return;
}

bool solution(string instr, vector<int> alpha) {
	// 철자 하나씩 들어오는데로 standard의 알파벳 배열에서 빼주기
	for (auto ch : instr) {
		int idx = ch - 'A';
		alpha[idx]--;
	}

	// 철자가 더 많은 경우와 적은 경우를 계산하기 위한 두 변수
	int add = 0, sub = 0;
	
	for (int i = 0; i < alpha.size(); i++) {
		if (alpha[i] > 0) add += alpha[i];
		if (alpha[i] < 0) sub += alpha[i];
	}

	// add와 sub가 둘 다 -1 이상, 1 이하인 경우에만 비슷한 단어로 취급
	if (( - 1 <= add && add <= 1) && ( - 1 <= sub && sub <= 1))
		return true;

	return false;
}

// 첫 string을 입력 받고 초기 설정을 해주는 메서드
void getFirstString(vector<int>& alpha) {
	string str;
	cin >> str;

	reset(alpha);
	count(str, alpha);

	return;
}

// string을 입력 받으며 첫 string과 비교해주는 메서드
int getStrings(int n, vector<int>& alpha) {
	int ans = 0;
	while (--n) {
		string instr;
		cin >> instr;

		if (solution(instr, alpha)) {
			ans++;
			continue;
		}
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);  cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> alpha(26, 0);
	getFirstString(alpha);

	cout << getStrings(n, alpha) << "\n";

	return 0;
}