#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(string begin, string target, vector<string> words) {
	int answer = 0;

	int wordsNum = words.size();
	int wordCnt = begin.size();
	vector<int> visit(wordsNum, 0);
	queue<pair<string, int>> qu;

	qu.push({ begin, 0 });

	int diff;
	while (!qu.empty()) {
		string start = qu.front().first;
		int count = qu.front().second;

		qu.pop();

		for (int i = 0; i < wordsNum; i++) {
			diff = 0;
			if (visit[i] != 0) continue;
			for (int j = 0; j < wordCnt; j++) {
				if (start[j] != words[i][j])
					diff++;
			}

			if (diff == 1) {
				if (words[i] == target)
					return count + 1;
				visit[i] = 1;
				qu.push({ words[i], count + 1 });
			}
		}
	}

	return answer;
}