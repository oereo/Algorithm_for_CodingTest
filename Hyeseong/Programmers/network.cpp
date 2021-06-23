#include <string>
#include <vector>

using namespace std;

bool dfs(int n, vector<vector<int>>& computers, int idx) {
	if (!computers[idx][idx]) return false;
	computers[idx][idx] = 0;

	for (int i = 0; i < n; i++) {
		if (computers[idx][i])
			dfs(n, computers, i);
	}

	return true;
}

int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (computers[i][i] && dfs(n, computers, i))
			answer++;
	}

	return answer;
}