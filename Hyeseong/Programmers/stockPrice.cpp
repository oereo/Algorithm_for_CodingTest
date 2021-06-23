#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
	vector<int> answer;
	int size = prices.size();
	int idx = 0;

	while (1) {
		int ans = 0;

		if (idx == size) {
			break;
		}

		for (int i = idx + 1; i < size; i++) {
			ans++;
			if (prices[idx] > prices[i])
				break;
		}

		idx++;

		answer.push_back(ans);
	}

	return answer;
}