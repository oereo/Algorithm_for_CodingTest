#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string part(string w) {
	string u, v;
	int open = 0, close = 0;
	bool perfect = true;

	if (w.size() == 0) return w;

	u += w[0];
	if (w[0] == '(') open++;
	else close++;

	int i = 1;
	while (open - close != 0) {
		if (open - close < 0) //닫는 괄호가 먼저 나오는 경우가 있으면 올바른 문자열 X
			perfect = false;
		u += w[i];
		if (w[i] == '(') open++;
		else close++;
		i++;
	}

	v = w.substr(i, w.size() - i);

	if (perfect) {
		string temp = part(v);
		return u += temp;
	}
	else {
		string temp = "(" + part(v) + ")";
		u = u.substr(1, u.size() - 2);
		for (int j = 0; j < u.size(); j++) {
			if (u[j] == '(') u[j] = ')';
			else u[j] = '(';
		}
		temp += u;
		return temp;
	}
}

string solution(string p) {
	string answer = "";

	answer = part(p);

	return answer;
}

int main() {
	cout << solution("(()())()");
	return 0;
}