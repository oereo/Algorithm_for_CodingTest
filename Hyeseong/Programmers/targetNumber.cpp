#include <string>
#include <vector>

using namespace std;

void dfs(vector<int> numbers, int target, int& answer, int count = 0, int sum = 0) {
	if (count == numbers.size()) {
		if (sum == target)
			answer++;
		return;
	}
	else {
		dfs(numbers, target, answer, count + 1, sum + numbers[count]);
		dfs(numbers, target, answer, count + 1, sum - numbers[count]);
	}
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	dfs(numbers, target, answer);
	return answer;
}