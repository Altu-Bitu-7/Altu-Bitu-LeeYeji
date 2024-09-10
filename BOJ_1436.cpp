#include <iostream>
#include <string>

using namespace std;

int apocalypseNumber(int n) {
	int num = 666;
	int count = 0;

	while (true) {
		string str_num = to_string(num);

		if (str_num.find("666") != string::npos) {
			count++;
		}

		if (count == n) {
			break;
		}
		
		num++;
	} 
	return num;
}

int main() {
	int n; int ans;
	cin >> n;

	ans = apocalypseNumber(n);
	cout << ans << endl;

	return 0;
}