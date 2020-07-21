#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv)
{
	int test_case;
	int T, N, X;

	// freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> X;
		vector<vector<int>> map(N * 2, vector<int>(N));
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cin >> map[i][j];
				map[j + N][i] = map[i][j];
			}
		}
		int answer = 0;
		for (int i = 0; i < N * 2; i++)
		{
			int now = map[i][0];
			int count = 1;
			bool check = true;
			for (int j = 1; j < N; j++)
			{
				if (map[i][j] == now)
				{ // 같은 높이인 경우
					count++;
					continue;
				}
				if (map[i][j] - now == 1)
				{ // 1칸 더 높은 경우
					if (count >= X)
					{
						now = map[i][j];
						count = 1;
						continue;
					}
					check = false;
					break;
				}
				if (map[i][j] - now == -1)
				{ // 1칸 더 낮은 경우
					now = map[i][j];
					count = 1;
					for (int k = 1; k < X; k++)
					{
						j++;
						if (j < N && map[i][j] == now)
						{
							count++;
						}
					}
					if (count == X)
					{
						count = 0;
						continue;
					}
					check = false;
					break;
				}
				check = false;
				break;
			}
			if (check)
				answer++;
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;
}