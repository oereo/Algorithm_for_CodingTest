#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int D, W, K;
bool film[13][20];
bool film_copy[13][20];
vector<pair<int, bool>> change;

bool inspect() {
	for (int i = 0; i < W; i++) {
		int now = film[0][i];
		int count = 1;
		for (int j = 1; j < D; j++) {
			if (count == K) break;
			if (now == film[j][i]) count++;
			else {
				now = film[j][i];
				count = 1;
			}
		}
		if (count < K)
			return false;
	}
	return true;
}

bool DFS(int start, int k) {
	int len = change.size();
	if (len == k) {
		for (auto i : change) {
			memset(film[i.first], i.second, sizeof(film[i.first]));
		}
		bool check = inspect();
		memcpy(film, film_copy, sizeof(film));
		return check;
	}
	for (int i = start; i < D; i++) {
		change.push_back({ i,0 });
		if (DFS(i + 1, k)) return true;
		change.pop_back();
		change.push_back({ i,1 });
		if (DFS(i + 1, k)) return true;
		change.pop_back();
	}
	return false;
}



int main(int argc, char** argv) {
	int test_case, answer;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		// 입력받기
		cin >> D >> W >> K;
		memset(film, 0, sizeof(film));
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> film[i][j];
			}
		}
		memcpy(film_copy, film, sizeof(film_copy));

		// 조합 & 검사하기
		answer = K;
		for (int k = 0; k < K; k++) {
			change.clear();
			if (DFS(0, k)) {
				answer = k;
				break;
			}
		}

		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}