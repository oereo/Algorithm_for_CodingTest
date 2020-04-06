#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int n, long long k)
{
    vector<long long> factorial(n - 1, 1);
    for (int i = 1; i < n - 1; i++)
    {
        factorial[i] = factorial[i - 1] * (i + 1);
    }
    reverse(factorial.begin(), factorial.end());

    vector<int> count(n);
    int idx = 0;
    k--;
    while (k != 0)
    {
        if (k - factorial[idx] < 0)
        {
            idx++;
            continue;
        }
        k -= factorial[idx];
        count[idx]++;
    }

    vector<int> num(n);
    for (int i = 1; i <= n; i++)
    {
        num[i - 1] = i;
    }

    vector<int> answer(n);
    for (int i = 0; i < n; i++)
    {
        answer[i] = num[count[i]];
        num.erase(num.begin() + count[i]);
    }
    return answer;
}