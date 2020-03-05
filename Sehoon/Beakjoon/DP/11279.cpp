#include<iostream>
#include<queue>

using namespace std;

int main() {

	int N = 0;
	priority_queue<int, vector<int>, less<int>> q;
	int NUMBER = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> NUMBER;
		if (NUMBER == 0) {
			if (q.empty()) {
				cout<<"결과" << "0" << endl;
			}
			else {
				cout << "결과" << q.top() << endl;
				q.pop();
			}
		}
		else {
			q.push(NUMBER);
		}

	}
	return 0;

}