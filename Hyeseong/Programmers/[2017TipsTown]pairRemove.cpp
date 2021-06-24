#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
	int answer = -1;
	stack<char> str;

	for (int i = 0; i < s.size(); i++) {
		if (str.empty() || str.top() != s[i]) {
			str.push(s[i]);
		}
		else if (str.top() == s[i]) {
			str.pop();
		}
	}

	if (str.size() == 0) answer = 1;
	else answer = 0;

	return answer;
}