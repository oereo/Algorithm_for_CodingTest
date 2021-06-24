#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	vector<double> failRate;
	double notClear = 0;
	double reached = 0;

	for (int i = 1; i <= N; i++) {
		for (int stage : stages) {
			if (stage > i) reached++;
			else if (stage == i) {
				reached++;
				notClear++;
			}
		}
		if (reached == 0) failRate.push_back(0);
		else
			failRate.push_back(notClear / reached);
		reached = 0;
		notClear = 0;
	}

	for (int i = 0; i < N; i++)
	{
		auto itr = max_element(failRate.begin(), failRate.end());
		answer.push_back(itr - failRate.begin() + 1);
		*itr = -111;
	}

	return answer;
}