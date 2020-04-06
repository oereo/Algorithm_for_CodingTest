#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, int m, vector<vector<int>> edge_list, int k, vector<int> gps_log)
{
    vector<vector<int>> adj(n + 1);
    for (auto e : edge_list)
    {
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    // DP[i][j] : i번째 경로에서 j번 도시를 갈 경우 고쳐야하는 최소 횟수
    vector<vector<int>> DP(k - 1, vector<int>(n + 1, 987654321));
    DP[0][gps_log[0]] = 0;
    for (int i = 1; i < k - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // i번째 경로에 해당하는 도시가 맞는 경우 add = 0, 아니면 1
            int add = (gps_log[i] == j ? 0 : 1);
            // 이전 경로의 도시에 그대로 있는 경우
            DP[i][j] = min(DP[i][j], DP[i - 1][j] + add);
            // 도시 j와 연결된 도시의 이전 경로의 값 비교하여 최소값 구하기
            for (auto p : adj[j])
            {
                DP[i][j] = min(DP[i - 1][p] + add, DP[i][j]);
            }
        }
    }

    // answer : 마지막 경로의 도시와 연결된 도시들의 이전 경로에서의 DP값 중 최소값
    int answer = 987654321;
    for (auto p : adj[gps_log.back()])
    {
        answer = min(answer, DP[k - 2][p]);
    }
    if (answer > 987654321 / 2)
        answer = -1;
    return answer;
}

// 참고 : https://wwiiiii.tistory.com/entry/%EC%B9%B4%EC%B9%B4%EC%98%A4-Code-Festival-%EB%B3%B8%EC%84%A0-16%EB%B2%88-%ED%92%80%EC%9D%B4