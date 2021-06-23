#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void dfs(vector<vector<string>> tickets, vector<int>& visit, string start, vector<string>& answer, int count) {
	answer.push_back(start);

	if (count == tickets.size()) {
		return;
	}

	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == start && visit[i] != 1) {
			visit[i] = 1;
			dfs(tickets, visit, tickets[i][1], answer, count + 1);
			visit[i] = 0;
		}
	}
}

vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;

	int ticketNum = tickets.size();
	vector<int> visit(ticketNum, 0);

	sort(tickets.begin(), tickets.end());

	dfs(tickets, visit, "ICN", answer, 0);


	return answer;
}

int main() {
	vector<vector<string>> tickets = { {"ICN", "SFO"},{"ICN", "ATL"},{"SFO", "ATL"},{"ATL", "ICN"},{"ATL","SFO"} };

	vector<string> answer = solution(tickets);

	for(int i=0;i<tickets.size();i++)
	cout << answer[i] << endl;

	return 0;
}