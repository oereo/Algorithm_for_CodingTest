#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void sort(vector<int>& array) {
	vector<int> sortedArr;
	int min = 0;
	int size = array.size();
	for (int i = 0; i < size; i++) {
		min = *min_element(array.begin(), array.end());
		sortedArr.push_back(min);
		array.erase(find(array.begin(), array.end(), min));
	}
	array = sortedArr;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		vector<int> arr;
		arr.assign(array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
		sort(arr);
		answer.push_back(arr[commands[i][2] - 1]);
	}

	return answer;
}

int main() {
	vector<int> answer = solution({ 1, 5, 2, 6, 3, 7, 4 }, { {2, 5, 3}, {4, 4, 1}, {1, 7, 3} });

	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i];
	}
}