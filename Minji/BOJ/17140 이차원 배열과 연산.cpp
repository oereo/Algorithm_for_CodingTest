#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

struct cmp {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if (a.second == b.second)
			return a.first > b.first;
		else
			return a.second > b.second;
	}
};

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	int A[100][100] = { 0 };
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}

	int answer = 0;
	int row = 3, col = 3, cnt = 0;
	int i, j;
	unordered_map<int, int> dic;
	priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
	while (A[r - 1][c - 1] != k) {
		if (answer == 100) {
			answer = -1;
			break;
		}

		if (row >= col) {	// R 연산
			for (i = 0; i < row; i++) {
				cnt = 0;
				dic.clear();
				for (j = 0; j < col; j++) {
					if (A[i][j] == 0) continue;
					dic[A[i][j]]++;
				}
				for (auto d : dic) {
					pq.push({ d.first, d.second });
					cnt++;
				}

				for (j = 0; j < cnt; j++) {
					if (j == 50) break;
					A[i][j * 2] = pq.top().first;
					A[i][j * 2 + 1] = pq.top().second;
					pq.pop();
				}
				for (int k = j * 2; k < row; k++)
					A[i][k] = 0;

				if (cnt * 2 > col && cnt <= 50)
					col = cnt * 2;
			}
		}
		else {	// C 연산
			for (i = 0; i < col; i++) {
				cnt = 0;
				dic.clear();
				for (int j = 0; j < row; j++) {
					if (A[j][i] == 0) continue;
					dic[A[j][i]]++;
				}
				for (auto d : dic) {
					pq.push({ d.first, d.second });
					cnt++;
				}

				for (j = 0; j < cnt; j++) {
					if (j == 50) break;
					A[j * 2][i] = pq.top().first;
					A[j * 2 + 1][i] = pq.top().second;
					pq.pop();
				}
				for (int k = j * 2; k < row; k++)
					A[k][i] = 0;

				if (cnt * 2 > row && cnt <= 50)
					row = cnt * 2;
			}
		}

		answer++;
	}

	cout << answer;
}