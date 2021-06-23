#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
	int answer = 0;
	int total = 0;

	sort(d.begin(), d.end());

	for (int i = 0; i < d.size(); i++) {
		if (total + d[i] <= budget) {
			total += d[i];
			answer++;
		}
		else break;
	}

	return answer;
}