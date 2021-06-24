#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	vector<int> clothesNum(n, 1);

	for (int lostNum : lost) {
		clothesNum[lostNum - 1]--;
	}
	for (int reserveNum : reserve) {
		clothesNum[reserveNum - 1]++;
	}

	for (int i = 0; i < n; i++) {
		if (clothesNum[i] == 0) {
			if (i != n - 1 && clothesNum[i + 1] == 2) {
				clothesNum[i]++;
				clothesNum[i + 1]--;
			}
			else if (i && clothesNum[i - 1] == 2) {
				clothesNum[i]++;
				clothesNum[i - 1]--;
			}
		}
	}

	for (int num : clothesNum) {
		if (num != 0) answer++;
	}

	return answer;
}