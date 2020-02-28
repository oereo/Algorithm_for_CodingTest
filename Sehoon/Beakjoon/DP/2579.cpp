#include<iostream>
#include<algorithm>

using namespace std;

int dp[1000] = { 0 };
int a[1000] = { 0 };
int b[1000] = { 0 };
int score[1000] = { 0 };
int N = 0;

int main() {

	

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> score[i];
	}
	a[1] = score[1];
	b[1] = 0;
	a[2] = score[1]+score[2];
	b[2] = score[2];


	for (int i = 3; i <= N; i++) {
		a[i] = b[i - 1] + score[i];
		b[i] = max(a[i - 2],b[i-2] )+ score[i];
	}
	dp[N] = max(a[N], b[N]);
	cout << dp[N];

	return 0;
}