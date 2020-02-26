#include<iostream>
#include<algorithm>

using namespace std;

// 배열 초기화에는 중괄호로 묶인 이니셜라이저 목록이 필요합니다.
// 배열 형식 int [100]은 할당할 수 없습니다.
int dp[1002][300] = { 0 };
int N = 0;
int house[1002][300] = { 0 };
int MIN = 0;
int arr[100] = { 0 };

int main() {

	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> house[i][j];
		}
	}
	for (int i = 1; i <= 3; i++) {
		dp[1][i] = house[1][i];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= 3; j++) {
			if (j == 1) {

				MIN = min(dp[i - 1][2], dp[i - 1][3]);

				//dp[i][j] = MIN + house[i][j];
			}
			else if (j == 2) {
				MIN = min(dp[i - 1][1], dp[i - 1][3]);

				//dp[i][j] = MIN + house[i][j];
			}
			else if (j == 3) {
				MIN = min(dp[i - 1][1], dp[i - 1][2]);

				
			}
			dp[i][j] = MIN + house[i][j];
		}
	}

	for (int i = 1; i <= 3; i++) {
		
		arr[i] = dp[N][i];
		
	}
	sort( arr, arr + 4 );
	cout << arr[1];
	
	return 0;

}