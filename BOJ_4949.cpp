#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool checkIsBalanced(string str) {
    stack<char> chars;
    bool is_balanced = true;

    for (char ch : str) {
        // 왼쪽 괄호는 단순히 스택에 넣기만 하기
        if (ch == '[' || ch == '(')
            chars.push(ch);

        // 오른쪽 괄호 처리
        // 1. 왼쪽 괄호가 직전에 있는지 확인하기
        // 2. 없다면 isBalanced도 false로 처리하고 break 시키기
        else if (ch == ']') {
            if (!chars.empty() && chars.top() == '[')
                chars.pop();
            else {
                is_balanced = false;
                break;
            }
        }
        else if (ch == ')') {
            if (!chars.empty() && chars.top() == '(')
                chars.pop();
            else {
                is_balanced = false;
                break;
            }
        }
    }

    // !주의! 모든 괄호가 처리되고, 스택이 비어있어야 균형이 맞음
    if (!chars.empty()) {
        is_balanced = false;
    }

    return is_balanced;
}

int main() {
    string str;

    while (true) {

        // getline으로 한 줄 통째로 받기
        getline(cin, str);

        if (str == ".") {
            return 0;
        }

        // 균형 여부 확인
        if (checkIsBalanced(str)) {
            cout << "yes\n";
        }
        else {
            cout << "no\n";
        }
    }

    return 0;
}
