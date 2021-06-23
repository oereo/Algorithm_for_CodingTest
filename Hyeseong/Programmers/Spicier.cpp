#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<int, vector<int>, greater<int>> scovPq(scoville.begin(), scoville.end());

	while (scovPq.size() > 1 && scovPq.top() < K) {
		int first = scovPq.top();
		scovPq.pop();
		int second = scovPq.top();
		scovPq.pop();
		scovPq.push(first + 2 * second);
		answer++;
	}

	if (scovPq.top() < K) return -1;

	return answer;
}