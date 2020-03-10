/*
각 집들은 서로 인접한 집들과 방범장치가 연결되어 있기 때문에 인접한 두 집을 털면 경보가 울립니다.
각 집에 있는 돈이 담긴 배열 money가 주어질 때, 도둑이 훔칠 수 있는 돈의 최댓값을 return 하도록 solution 함수를 작성하세요.

예:
money	        return
[1, 2, 3, 1]	4
*/

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int dp[1000000];
int housenumber[1000000];

int solution(vector<int> money) {
    int answer = 0;
    for(int i = 0 ; i < money.size(); i++){
        housenumber[i] = money[i];
    }
    return answer;
}