#include <iostream>
#include <vector>

using namespace std;

// 바퀴 초기화 함수
vector<char> resetWheel(int n) {
    return vector<char>(n, '?');
}

// 시계 방향으로 돌렸을 때의 새로운 위치 계산 함수
int calculatePosition(int n, int position, int inc) {
    return (position + inc) % n;
}

// 알파벳 중복 체크 함수
bool checkDuplicates(int n, vector<char>& wheel) {
    vector<bool> alphabets(26, false);

    for (int i = 0; i < n; i++) {
        if (wheel[i] != '?') {
            if (alphabets[wheel[i] - 'A']) {
                return false; // 중복 발견
            }
            alphabets[wheel[i] - 'A'] = true;
        }
    }

    return true;
}

// 바퀴 회전 및 알파벳 배치 함수
int rotates(int n, int k, vector<char>& wheel) {
    int current_position = 0;
    int inc;
    char letter;

    for (int i = 0; i < k; i++) {
        cin >> inc >> letter;

        current_position = calculatePosition(n, current_position, inc);

        if (wheel[current_position] != '?') {
            if (wheel[current_position] != letter) {
                cout << "!";
                exit(0);
            }
        }
        else {
            wheel[current_position] = letter;
        }
    }

    return current_position;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> lucky_wheel = resetWheel(n);

    int final_position = rotates(n, k, lucky_wheel);

    if (!checkDuplicates(n, lucky_wheel)) {
        cout << "!";
        return 0;
    }
    else {
        // final_position에서부터 시계 방향으로 출력
        for (int i = 0; i < n; i++) {
            cout << lucky_wheel[final_position];
            final_position = (final_position - 1 + n) % n; // 시계 방향으로 출력
        }
    }

    return 0;
}