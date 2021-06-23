#include <iostream>
#include <string>
#include <vector>

using namespace std;

void crane(vector<vector<int>> &board, vector<int>& basket, int move, int& answer) {
	int target = 0;

	for (int i = 0; i < board.size(); i++) {
		if (board[i][move]) {
			target = board[i][move];
			board[i][move] = 0;
			break;
		}
	}

	if (target) {
		if (basket.size() && target == basket.back()) {
			basket.pop_back();
			answer += 2;
		}
		else {
			basket.push_back(target);
		}
	}
}

int solution(vector<vector<int>> board, vector<int> moves) {
	int answer = 0;
	vector<int> basket;

	for (int i = 0; i < moves.size(); i++) {
		crane(board, basket, moves[i] - 1, answer);
	}

	return answer;
}