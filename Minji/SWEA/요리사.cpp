#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T, N;

	// freopen("input.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> N;
		vector<vector<int>> S(N, vector<int>(N));
		for (int i = 0; i < N; i++)	{
			for (int j = 0; j < N; j++)	{
				cin >> S[i][j];
			}
		}
		vector<bool> idx(N);
		for (int i = 0; i < N / 2; i++) {
			idx[N - i - 1] = 1;
		}
		int MIN = 987654321;
		do {
			int sum1 = 0;
			int sum2 = 0;
			vector<int> num1;
			vector<int> num2;
			for (int i = 0; i < N; i++)	{
				if (idx[i] == 1) {
					num1.push_back(i);
				}
				else {
					num2.push_back(i);
				}
			}
			for (int i = 0; i < N/2; i++) {
				for (int j = 0; j < N/2; j++) {
					sum1 += S[num1[i]][num1[j]];
					sum2 += S[num2[i]][num2[j]];
				}
			}
			int result = abs(sum1 - sum2);
			if (MIN > result)
				MIN = result;
		} while (next_permutation(idx.begin(), idx.end()));

		cout << "#" << test_case << " " << MIN << endl;
	}
	return 0;
}