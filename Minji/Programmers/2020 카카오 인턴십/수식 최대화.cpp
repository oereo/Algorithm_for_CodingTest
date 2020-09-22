#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long cal(long long a, long long b, char c)
{
    switch (c)
    {
    case '*':
        return a * b;
    case '+':
        return a + b;
    case '-':
        return a - b;
    }
}

long long solution(string expression)
{
    vector<char> opers;
    vector<long long> nums;
    int len = expression.size();
    int sidx = 0;
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(expression[i]))
        {
            opers.push_back(expression[i]);
            nums.push_back(stoi(expression.substr(sidx, i - sidx)));
            sidx = i + 1;
        }
    }
    nums.push_back(stoi(expression.substr(sidx)));

    vector<char> priority = {'*', '+', '-'};
    int oper_len = opers.size();
    long long answer = 0;
    vector<char> temp_opers;
    vector<long long> temp_nums;
    int temp_len;
    do
    {
        temp_opers = opers;
        temp_nums = nums;
        temp_len = oper_len;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < temp_len; j++)
            {
                if (temp_opers[j] == priority[i])
                {
                    temp_nums[j] = cal(temp_nums[j], temp_nums[j + 1], temp_opers[j]);
                    temp_nums.erase(temp_nums.begin() + j + 1);
                    temp_opers.erase(temp_opers.begin() + j);
                    temp_len--;
                    j--;
                }
            }
        }
        if (answer < abs(temp_nums[0]))
            answer = abs(temp_nums[0]);
    } while (next_permutation(priority.begin(), priority.end()));

    return answer;
}