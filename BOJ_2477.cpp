#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<pair<int, int>> edges(6);

	int n; cin >> n;
	int x = 0, y = 0;


	for (int i = 0; i < 6; ++i) {
		int dir, len;
		cin >> edges[i].first >> edges[i].second;
	}

	// max_wid, max_hei;
	int max_wid = 0, max_hei = 0;
	int max_wid_idx = 0, max_hei_idx = 0;


	// 가장 큰 가로, 세로 길이와 인덱스 찾기
	for (int i = 0; i < 6; ++i) {
		if (edges[i].first == 1 || edges[i].first == 2) {
			if (edges[i].second > max_wid) {
				max_wid = edges[i].second;
				max_wid_idx = i;
			}
		}
		else if (edges[i].first == 3 || edges[i].first == 4) {
			if (edges[i].second > max_hei) {
				max_hei = edges[i].second;
				max_hei_idx = i;
			}
		}
	}

	// 작은 직사각형의 변 찾기(큰 변에 인접한 두 변)
	// 육각형의 변이 6개라는 것을 이용해서 직사각형의 큰 변에 인접한 변 찾기
	int min_wid = edges[(max_wid_idx + 3) % 6].second;
	int min_hei = edges[(max_hei_idx + 3) % 6].second;

	// 면적 계산
	int max_rec = max_wid * max_hei;
	int min_rec = min_wid * min_hei;
	int rec = max_rec - min_rec;

	cout << rec * n << "\n";

	return 0;
}