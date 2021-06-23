#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(vector<int> numbers, string hand) {
	string answer = "";
	int lastLeft = 10;
	int lastRight = 12;
	int leftDist = 0;
	int rightDist = 0;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == 0) numbers[i] = 11;
		if (numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7) {
			answer += "L";
			lastLeft = numbers[i];
		}
		else if (numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9) {
			answer += "R";
			lastRight = numbers[i];
		}
		else {
			int tempL = abs(lastLeft - numbers[i]);
			int tempR = abs(lastRight - numbers[i]);

			leftDist = tempL / 3 + tempL % 3;
			rightDist = tempR / 3 + tempR % 3;

			if (leftDist == rightDist) {
				if (hand == "right") {
					answer += "R";
					lastRight = numbers[i];
				}
				else {
					answer += "L";
					lastLeft = numbers[i];
				}
			}
			else if (leftDist > rightDist) {
				answer += "R";
				lastRight = numbers[i];
			}
			else {
				answer += "L";
				lastLeft = numbers[i];
			}
		}
	}

	return answer;
}