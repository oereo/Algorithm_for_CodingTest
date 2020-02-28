#include<iostream>

using namespace std;

int dp[50] = { 1,0 };
int ap[50] = { 0,1 };
int Num = 0;
int idx = 0;
//pair<int, int> p0;
//pair<int, int> p1;
//pair<int, int>p_res;

int main() {
	//p0 = make_pair(1, 0);
	//p1 = make_pair(0, 1);
	//p_res = p0 + p1;
	cin >> Num;
	for (int i = 1; i <= Num; i++) {
		cin >> idx;
		for (int i = 2; i <= idx; i++) {
			dp[i] = dp[i - 1] + dp[i - 2];
			ap[i] = ap[i - 1] + ap[i - 2];

		}
		cout << dp[idx] << " "<<ap[idx] << endl;
		
	}
	return 0;
}