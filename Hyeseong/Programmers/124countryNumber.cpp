#include <iostream>
#include <string>
#include <vector>

using namespace std;

void oneTwoFour(int n, string& answer) {
	if (n == 1 || n == 2) answer += to_string(n);
	else if (n == 3) answer += "4";
	
	else if ((n - 1) / 3) {
		oneTwoFour((n - 1) / 3, answer);
		if (n % 3 == 0) answer += "4";
		else answer += to_string(n % 3);
	}
}

string solution(int n) {
	string answer = "";

	oneTwoFour(n, answer);

	return answer;
}

int main() {
	cout<<solution(4);

	return 0;
}