#include <iostream>
#include <vector>

using namespace std;

// 방향 벡터
int dx[4] = { 0, 1, 1, -1 };
int dy[4] = { 1, 0, 1, 1 };  // 가로 방향에서 오른쪽으로 가도록 수정

// 2차원 vector로 바둑판을 선언
vector<vector<int>> board(19, vector<int>(19));

bool check(int x, int y, int color) {
	for (int d = 0; d < 4; d++) {
		// 우선 현재 위치에 해당 색의 돌이 하나 있으므로 count를 1로 초기화
		int count = 1;

		// 연속된 알 개수 확인
		int nx = x + dx[d];
		int ny = y + dy[d];

		// 5개의 알이 연속되는지 확인
		while (nx >= 0 && nx < 19 && ny >= 0 && ny < 19 && board[nx][ny] == color) {
			count++;
			// 6개 이상이면 이긴 것이 아님
			if (count == 6) break;
			nx += dx[d];
			ny += dy[d];
		}

		// 연속된 5개일 때, 이전 칸 확인해서 6개가 아니면 승리
		if (count == 5) {
			// 이전 방향도 확인해 6개 이상 연속인지 확인
			int px = x - dx[d];
			int py = y - dy[d];
			if (px >= 0 && px < 19 && py >= 0 && py < 19 && board[px][py] == color) {
				continue;
			}
			return true;
		}
	}

	return false;
}

void searching() {
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			// 현재 위치에 바둑알이 없으면 패스
			if (board[i][j] == 0) {
				continue;
			}

			// 현재 바둑알 색 확인
			int color = board[i][j];
			if (check(i, j, color)) {
				// 승리한 경우
				cout << color << "\n";
				// 가장 왼쪽 또는 위에 있는 바둑알 출력
				cout << i + 1 << " " << j + 1 << "\n";
				return;
			}
		}
	}

	// 승부가 결정되지 않았을 경우
	cout << 0 << "\n";
}

int main() {
	// 바둑판 입력 받기
	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			cin >> board[i][j];
		}
	}

	searching();  // 바둑판 상태 탐색

	return 0;
}
