#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct {
	int row;
	int col;
}Pos;

queue<Pos> qu;
vector<int> dx = { 1, 0, -1, 0 };
vector<int> dy = { 0, 1, 0, -1 };

void bfs(vector<vector<int>> picture, vector<vector<bool>>& visited, Pos start, vector<int>& answer, int m, int n) {
	int size = 1;

	answer[0]++;

	qu.push(start);
	visited[start.row][start.col] = true;

	while (!qu.empty()) {
		Pos curr = qu.front();

		if (curr.row == m - 1 && curr.col == n - 1) break;

		qu.pop();

		for (int i = 0; i < 4; i++) {
			Pos next = { curr.row + dy[i], curr.col + dx[i] };
			if (next.row < 0 || next.col < 0 || next.row >= m || next.col >= n || visited[next.row][next.col])
				continue;
			if (picture[next.row][next.col] == picture[curr.row][curr.col]) {
				qu.push(next);
				visited[next.row][next.col] = true;
				size++;
			}
		}
	}
	if (answer[1] < size) answer[1] = size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2, 0);
	vector<vector<bool>> visited(m, vector<bool>(n, false));

	for (int row = 0; row < m; row++) {
		for (int col = 0; col < n; col++) {
			if (picture[row][col] && !visited[row][col]) {
				bfs(picture, visited, { row, col }, answer, m, n);
			}
		}

	}

	return answer;
}

int main() {
	int m = 6, n = 4;
	vector<vector<int>> picture = { {1,1,1,0}, {1,2,2,0}, {1,0,0,1}, {0,0,0,1}, {0,0,0,3}, {0,0,0,3} };

	vector<int> answer = solution(m, n, picture);

	cout << answer[0] << answer[1];

	return 0;
}