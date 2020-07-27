#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, C, MAX;

vector<vector<int>> hive;
vector<vector<int>> square;
vector<vector<int>> result;
vector<int> choose;

void dfs(int i, int j, int m, int count) {
	int len = choose.size();
	if (len == count) {
		int sum1 = 0;
		int sum2 = 0;
		for (int a = 0; a < len; a++) {
			sum1 += hive[i][choose[a]];
			sum2 += square[i][choose[a]];
		}
		if (sum1 <= C) {
			if (MAX < sum2)
				MAX = sum2;
		}
		return;
	}

	for (int a = j; a < m; a++)	{
		choose.push_back(a);
		dfs(i, a + 1, m, count);
		choose.pop_back();
	}
}

int main(int argc, char** argv) {
	int test_case;
	int T, i, j, k, sum, answer;
	// freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		// 입력 받기
		cin >> N >> M >> C;
		hive.assign(N, vector<int>(N));
		square.assign(N, vector<int>(N));
		result.assign(N, vector<int>(N - M + 1));
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)	{
				cin >> hive[i][j];
				square[i][j] = hive[i][j] * hive[i][j];
			}
		}

		// 벌통 선택 시의 결과값 구하기
		vector<int> best;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N - M + 1; j++) {
				sum = 0;
				for (k = 0; k < M; k++)	{
					sum += hive[i][j + k];
					result[i][j] += square[i][j + k];
				}
				if (sum > C) {
					MAX = 0;
					choose.clear();
					for (k = 1; k < M; k++)	{
						dfs(i, j, j + M, k);
					}
					result[i][j] = MAX;
				}
			}
			best.push_back(*max_element(result[i].begin(), result[i].end()));
		}

		// 최대 수익 구하기
		sort(best.begin(), best.end());
		answer = best[N-1];
		answer += best[N-2];
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}