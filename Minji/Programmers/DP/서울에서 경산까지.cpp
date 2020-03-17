#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int K, vector<vector<int>> travel)
{
    // 자전거로만 간다고 가정
    int answer = 0;
    int len = travel.size();
    vector<pair<int, int>> diff(len);
    for (int i = 0; i < len; i++)
    {
        answer += travel[i][3]; // 자전거 모금액
        K -= travel[i][2];      // 자전거로 간 시간을 제한 시간에서 차감
        diff[i] = {travel[i][0] - travel[i][2], travel[i][1] - travel[i][3]};
    }

    // 제한 시간 내에 가능하면 도보로 변경하여 최대 모금액 구하기
    vector<vector<int>> DP(len + 1, vector<int>(K + 1));
    for (int i = 1; i <= len; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            if (j - diff[i - 1].first < 0)
            {
                DP[i][j] = DP[i - 1][j];
                continue;
            }
            DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - diff[i - 1].first] + diff[i - 1].second);
        }
    }
    answer += DP[len][K];
    return answer;
}