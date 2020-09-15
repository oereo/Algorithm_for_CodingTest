#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n)
{
    vector<int> answer(1);
    for (int i = 1; i < n; i++)
    {
        vector<int> temp = answer;
        reverse(temp.begin(), temp.end());
        answer.push_back(0);
        for (int t : temp)
            answer.push_back(!t);
    }
    return answer;
}