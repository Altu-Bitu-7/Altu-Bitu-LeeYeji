#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// string으로 덧셈 구현
// idea: 받아올림을 어떻게 구현할 것인가
// idea: 자리수를 맞춰 계산하는 방법 -> 1의 자리부터 통일
string addStrings(const string& num1, const string& num2) {
	string result;	// 결과값
	int carry = 0;	// 받아올림 할 수
	int sum = 0;	// 반복문에서 각 자리의 값으로 활용할 변수

	// 덧셈을 시작할 자리를 일의 자리로 설정해주기
	int i = num1.size() - 1, j = num2.size() - 1;

	// idea: 가장 높은 자리에 도달할 때까지

	while (i >= 0 || j >= 0 || carry) {
		// 받아올려진 수부터 반영
		sum = carry;
		// 각 숫자의 아스키 코드 값에서 0만큼 빼준 것이 진짜 숫자의 값
		if (i >= 0) sum += num1[i--] - '0';
		if (j >= 0) sum += num2[j--] - '0';

		// 받아 올림
		carry = sum / 10;
		// 계산된 각 자릿수에 '0'을 더해서 다시 string 값 부여
		result.push_back(sum % 10 + '0');
	}

	reverse(result.begin(), result.end());
	return result;
}

int main() {

	string a, b;

	cin >> a >> b;

	cout << addStrings(a, b);

	return 0;
}