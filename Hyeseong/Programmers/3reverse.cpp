#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n) {
	int answer = 0;
	vector<int> temp;

	while (n) {
		temp.push_back(n % 3);
		n /= 3;
	}

	reverse(temp.begin(), temp.end());

	for (int i = 0; i < temp.size(); i++) {
		answer += pow(3, i) * temp[i];
	}

	return answer;
}