#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	queue<int> days;
	int size = progresses.size();
	int ans = 1;

	for (int i = 0; i < size; i++) {
		int day = (100 - progresses[i] + speeds[i] - 1) / speeds[i];
		days.push(day);
	}

	int max = days.front();
	days.pop();

	while (1) {
		if (days.empty()) {
			answer.push_back(ans);
			break;
		}

		if (max >= days.front()) {
			ans++;
		}
		else {
			answer.push_back(ans);
			ans = 1;
			max = days.front();
		}

		days.pop();
	}

	return answer;
}