#include <iostream>
#include <algorithm>

using namespace std;

char isValidPosition(pair<int, char> pos) {
	if (pos.second < 'A' || 'H' < pos.second) {
		return false;
	}
	if (pos.first < 1 || 8 < pos.first) {
		return false;
	}
	return true;
}

pair<int, char> R(pair<int, char> pos) {
	pair<int, char> new_pos = make_pair(pos.first, pos.second + 1);
	return new_pos;
}

pair<int, char> L(pair<int, char> pos) {
	pair<int, char> new_pos = make_pair(pos.first, pos.second - 1);
	return new_pos;
}

pair<int, char> B(pair<int, char> pos) {
	pair<int, char> new_pos = make_pair(pos.first -1, pos.second);
	return new_pos;
}

pair<int, char> T(pair<int, char> pos) {
	pair<int, char> new_pos = make_pair(pos.first + 1, pos.second);
	return new_pos;
}

// 복합 명령의 경우 두 명령이 모두 유효 범위 내에서 수행 가능한지 확인한 후
// 두 명령을 수행해야하므로 이 함수 내에서 유효 범위인지 확인해줘야 함
pair<int, char> control(string comm, pair<int, char> pos) {
	pair<int, char> new_pos;

	if (comm == "R") {
		new_pos = R(pos);
	} else if (comm == "L") {
		new_pos = L(pos);
	} else if (comm == "B") {
		new_pos = B(pos);
	} else if (comm == "T") {
		new_pos = T(pos);
	} else if (comm == "RT") {
		new_pos = T(R(pos));
	} else if (comm == "LT") {
		new_pos = T(L(pos));
	} else if (comm == "RB") {
		new_pos = B(R(pos));
	} else if (comm == "LB") {
		new_pos = B(L(pos));
	}

	return new_pos;
}

void pairControl(pair<int, char>& king, pair<int, char>& stone) {
	pair<int, char> new_king;
	pair<int, char> new_stone;
	string com;

	cin >> com;

	new_king = control(com, king);


	// King의 위치 변화가 유효 범위 외라면 바로 리턴
	if (!isValidPosition(new_king))
		return;

	// king과 stone이 같은 자리에 있게 되는 경우 stone에 똑같은 연산 취하고
	// stone에 대해서도 유효 범위 확인해주고 값 바꿔주기
	if (new_king == stone) {
		new_stone = control(com, stone);
		if (isValidPosition(new_stone)) {
			king = new_king;
			stone = new_stone;

			return;
		}
	} else {
		// king의 위치 범위가 유효하지만 new_king != stone인 경우이므로
		// king만 바꿔서 리턴
		king = new_king;
	}

	return;
}


int main() {
	string kingPos, stonePos;
	int n;

	// 입력받은 시작 위치에서 어떻게 행과 열을 구분해낼 것인가?
	cin >> kingPos >> stonePos >> n;
	
	// string의 인덱스에 접근해서 행과 열 떼서 받기
	// 개인 선호에 따라 <행, 열>로 저장
	pair<int, char> king = make_pair(kingPos[1] - '0', kingPos[0]);
	pair<int, char> stone = make_pair(stonePos[1]- '0', stonePos[0]);


	while (n--) {
		pairControl(king, stone);
	}

	kingPos[0] = king.second; kingPos[1] = king.first + '0';
	stonePos[0] = stone.second; stonePos[1] = stone.first + '0';
	cout << kingPos << "\n" << stonePos;

	return 0;
}