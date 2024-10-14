#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int n;
int cnt_max = INT_MIN, cnt_min = INT_MAX;
int operators[4];

void operate(vector<int>& nums, int cnt, int num_idx) {
    // base case: 마지막 연산이 끝난 경우
    if (num_idx == n) {
        cnt_max = max(cnt_max, cnt);
        cnt_min = min(cnt_min, cnt);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        if (operators[i] > 0) {
            operators[i]--;  // 연산자 사용
            int new_cnt = cnt;

            // 사칙연산
            if (i == 0) new_cnt += nums[num_idx];  
            else if (i == 1) new_cnt -= nums[num_idx]; 
            else if (i == 2) new_cnt *= nums[num_idx];  
            else if (i == 3) new_cnt /= nums[num_idx]; 

            // 다음 숫자로 재귀 호출
            operate(nums, new_cnt, num_idx + 1);

            operators[i]++;  // 사용한 연산자 복구
        }
    }
}

int main() {
    // 입력 받기
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    // 첫 번째 숫자를 기준으로 연산 시작
    operate(nums, nums[0], 1);

    // 결과 출력
    cout << cnt_max << "\n" << cnt_min;

    return 0;
}
