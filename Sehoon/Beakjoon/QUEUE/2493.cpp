#include<iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t[100000];
	int res[100000];
	int N = 0;

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> t[i];
	}

	for (int i = N; i >= 1; i--) {
		for (int j = i - 1; j >= 2; j--) {
			if (t[i] < t[j]) {
				res[i] = j;

				break;
			}

		}

	}

	for (int i = 1; i <= N; i++) {
		cout << res[i];
	}

	return 0;
}