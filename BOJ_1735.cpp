#include <iostream>

using namespace std;

int findGcd(int n1, int n2) {
	// d를 더 작은 수로 세팅
	if (n1 < n2)
		swap(n1, n2);

	// gcd 구하기
	while (n2) {
		n1 %= n2;
		swap(n1, n2);
	}

	return n1;
}

int findLcm(int n1, int n2, int gcd) {
	int lcm = n1 * n2 / gcd;

	return lcm;
}

// 통분
int simplification(int& a, int& b, int& c, int& d) {
	int bd_gcd = findGcd(b, d);
	int bd_lcm = findLcm(b, d, bd_gcd);
	a *= (bd_lcm / b);
	c *= (bd_lcm / d);

	return bd_lcm;
}

// 약분
void abbreviate(int& numerator, int& denominator) {
	int gcd = findGcd(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;
}

int main() {
	int a, b, c, d;
	cin >> a >> b;
	cin >> c >> d;

	int bd_lcm = simplification(a, b, c, d);

	int ans = a + c;
	abbreviate(ans, bd_lcm);

	cout << ans << " " << bd_lcm;

	return 0;
}