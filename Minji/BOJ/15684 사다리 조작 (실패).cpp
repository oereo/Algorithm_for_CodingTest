#include <iostream>
#include <vector>

using namespace std;

// 주어진 TC는 모두 통과..

int N, M, H;
vector<vector<int>> map;

bool check() {
	for (int i = 0; i < N; i++)	{
		int a = i;
		for (int j = 0; j < H; j++)	{
			if (map[j][a] == 1)
				a++;
			else if (map[j][a] == -1)
				a--;
		}
		if (a != i)
			return false;
	}
	return true;
}

int main() {
	// 입력 받기
	cin >> N >> M >> H;
	map.assign(H, vector<int>(N));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a - 1][b - 1] = 1;
		map[a - 1][b] = -1;
	}

	// 최소 횟수로 가로선 추가하기
	int MIN = 4;
	if (check()) {
		cout << 0;
		return 0;
	}

	for (int a = 0; a < (N - 1) * H ; a++) { // 1개 추가
		int ax = a / (N - 1);
		int ay = a % (N - 1);

		if (map[ax][ay] != 0 || map[ax][ay + 1] != 0) continue;

		map[ax][ay] = 1;
		map[ax][ay + 1] = -1;

		if (check()) {
			cout << 1;
			return 0;
		}

		for (int b = a + 1; b < (N - 1) * H; b++)	{	// 2개 추가
			if (MIN == 2) break;

			int bx = b / (N - 1);
			int by = b % (N - 1);

			if (map[bx][by] != 0 || map[bx][by + 1] != 0) continue;

			map[bx][by] = 1;
			map[bx][by + 1] = -1;

			if (check()) {
				MIN = 2;
				map[bx][by] = 0;
				map[bx][by + 1] = 0;
				break;
			}

			for (int c = b + 1; c < (N - 1) * H; c++) {	// 3개 추가
				if (MIN == 3) break;

				int cx = c / (N - 1);
				int cy = c % (N - 1);

				if (map[cx][cy] != 0 || map[cx][cy + 1] != 0) continue;

				map[cx][cy] = 1;
				map[cx][cy + 1] = -1;

				if (check()) {
					MIN = 3;
					map[cx][cy] = 0;
					map[cy][cy + 1] = 0;
					break;
				}

				map[cx][cy] = 0;
				map[cx][cy + 1] = 0;
			}

			map[bx][by] = 0;
			map[bx][by + 1] = 0;
		}
		
		map[ax][ay] = 0;
		map[ax][ay + 1] = 0;
	}

	if (MIN != 4)
		cout << MIN;
	else
		cout << -1;
}