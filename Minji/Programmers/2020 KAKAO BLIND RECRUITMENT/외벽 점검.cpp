#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist)
{
    int weak_len = weak.size();
    int dist_len = dist.size();

    sort(dist.begin(), dist.end());
    for (int i = 0; i < weak_len - 1; i++)
    {
        weak.push_back(n + weak[i]);
    }

    int answer = -1;
    for (int i = 0; i < dist_len; i++)
    { // 투입한 친구 수
        for (int j = 0; j < weak_len; j++)
        { // 시작 지점 선택
            vector<int> temp;
            for (int k = dist_len - 1 - i; k < dist_len; k++)
            {
                temp.push_back(dist[k]);
            }

            do
            {
                int idx = 0;
                for (int k = 0; k <= i; k++)
                { // 친구 투입
                    int start = weak[j + idx] + temp[k];
                    while (weak[j + idx + 1] <= start)
                    {
                        idx++;
                    }
                    idx++;
                }
                if (idx >= weak_len)
                {
                    return i + 1;
                }
            } while (next_permutation(temp.begin(), temp.end()));
        }
    }
    return answer;
}