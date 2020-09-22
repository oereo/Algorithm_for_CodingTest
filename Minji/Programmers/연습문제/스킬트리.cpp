#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string skill, vector<string> skill_trees)
{
    int len = skill_trees.size();
    int skill_len = skill.size();
    int answer = len;
    for (int i = 0; i < len; i++)
    {
        vector<int> idx(skill_len);
        for (int j = 0; j < skill_len; j++)
        {
            idx[j] = skill_trees[i].find(skill[j]);
            if (idx[j] == -1) // 존재하지 않으면 100으로
                idx[j] = 100;
            // 인덱스 벡터가 오름차순이어야 함
            if (j - 1 < 0)
                continue;
            if (idx[j - 1] > idx[j])
            {
                answer--;
                break;
            }
        }
    }
    return answer;
}