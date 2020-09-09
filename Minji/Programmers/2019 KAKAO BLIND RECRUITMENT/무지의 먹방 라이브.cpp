#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}

int solution(vector<int> food_times, long long k)
{
    int len = food_times.size();
    long long total = 0;
    vector<pair<int, int>> idx_time;
    for (int i = 0; i < len; i++)
    {
        idx_time.push_back({i + 1, food_times[i]});
        total += food_times[i];
    }
    if (total <= k)
        return -1;

    k++;
    sort(idx_time.begin(), idx_time.end(), cmp);
    int now_len = len, idx = 0, MIN = 0;
    while (1)
    {
        if (k > (long long)now_len * (idx_time[idx].second - MIN))
        {
            k -= (long long)now_len * (idx_time[idx].second - MIN);
            MIN = idx_time[idx].second;
            while (1)
            {
                idx++;
                now_len--;
                if (idx_time[idx].second != MIN)
                    break;
            }
        }
        else
        {
            vector<int> temp;
            for (int i = idx; i < len; i++)
            {
                temp.push_back(idx_time[i].first);
            }
            sort(temp.begin(), temp.end());
            return temp[(k - 1) % now_len];
        }
    }
}