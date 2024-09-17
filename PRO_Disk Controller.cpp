7#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// pair의 두 번째 요소(second)를 기준으로 우선순위 큐에서 정렬 (작을수록 높은 우선순위)
struct cmp {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    // jobs 벡터를 요청 시간 기준으로 오름차순 정렬
    sort(jobs.begin(), jobs.end());

    // 요청 시간과 작업 시간을 저장할 우선순위 큐
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    int current_time = 0;
    int i = 0;

    while (true) {
        // 모든 작업을 처리했고 우선순위 큐도 비었으면 종료
        if (i >= jobs.size() && pq.empty()) {
            break;
        }

        // 현재 시간보다 먼저 요청된 작업을 우선순위 큐에 삽입
        while (i < jobs.size() && jobs[i][0] <= current_time) {
            pq.push({ jobs[i][0], jobs[i][1] });
            i++;
        }

        // 우선순위 큐에 작업이 있을 경우
        if (!pq.empty()) {
            answer += (current_time - pq.top().first + pq.top().second);
            current_time += pq.top().second;
            pq.pop();
        }
        else {
            // 우선순위 큐가 비어있으면 현재 시간을 다음 작업의 요청 시간으로 업데이트
            current_time = jobs[i][0];
        }
    }

    // 총 작업 시간의 평균을 계산
    answer /= jobs.size();

    return answer;
}