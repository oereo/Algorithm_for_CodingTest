#include<iostream>
#include<queue>

using namespace std;

int main() {

	int N = 0;
	cin >> N;
	int number = 0;

	queue<int> q;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		if (str == "push") {
			cin >> number;
			q.push(number);
		}
		else if (str == "pop") {
			if (!q.empty()) {
				cout << q.front() << endl;
				q.pop();
			}
			else {
				cout << "-1" << endl;
			}

		}
		else if (str == "size") {
			cout << q.size() << endl;
		}
		else if (str == "empty") {
			if (q.empty() == 1) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}

		}
		else if (str == "front") {
			if (!q.empty()) {
				cout << q.front() << endl;
			}
			else {
				cout << "-1" << endl;

			}

		}
		else if (str == "back") {
			if (!q.empty()) {
				cout << q.back() << endl;
			}
			else {
				cout << "-1" << endl;

			}

		}


	}
	return 0;

}