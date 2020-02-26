#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int r;
int sum;
vector<int> index;
vector<int> list;

void count() {
	cin >> N >> sum;
	
		for (int i = 0; i < N; i++) {
			int number;
			cin >> number;
			list.push_back(number);
		}
	
}


int main() {
	count();


	for (int i = 0; i < 3; i++) {
		index.push_back(1);
	}
	for (int i = 0; i < N - 3; i++) {
		index.push_back(0);
		sort(index.begin(), index.end(), greater<int>());

	}
	do {
		for (int i = 0; i < N; i++) {
			if (index[i] == 1)
				cout << list[i] << " ";
		}
		cout << '\n';
	} while (next_permutation(index.begin(), index.end(), greater<int>()));

	cout << endl;

	return 0;
}

