#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, float> a, pair<int, float> b)
{
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(int N, vector<int> stages)
{
    vector<int> cnt(N + 1);
    for (int s : stages)
        cnt[s - 1]++;
    int sum = cnt[N];

    vector<pair<int, float>> result(N);
    for (int i = N - 1; i >= 0; i--)
    {
        sum += cnt[i];
        result[i].first = i + 1;
        if (sum == 0)
            result[i].second = 0;
        else
            result[i].second = (float)cnt[i] / sum;
    }

    vector<int> answer;
    sort(result.begin(), result.end(), cmp);
    for (auto r : result)
        answer.push_back(r.first);
    return answer;
}