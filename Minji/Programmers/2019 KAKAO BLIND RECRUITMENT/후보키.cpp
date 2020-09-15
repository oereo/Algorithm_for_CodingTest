#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> relation)
{
    int col = relation[0].size();
    int row = relation.size();
    int count = 1;
    vector<vector<int>> result;
    vector<int> num(col); // 0 ~ col-1 숫자가 들어있는 벡터
    for (int i = 0; i < col; i++)
    {
        num[i] = i;
    }
    while (count <= col)
    {
        vector<int> idx(col);
        for (int i = 0; i < count; i++)
        {
            idx[col - i - 1] = 1;
        }
        // 조합 만들기
        do
        {
            vector<int> temp;
            for (int i = 0; i < col; i++)
            {
                if (idx[i] == 1)
                    temp.push_back(num[i]);
            }

            // 유일성 체크
            int temp_len = temp.size();
            bool check = true;
            map<string, int> dic;
            for (int i = 0; i < row; i++)
            {
                string a = "";
                for (int j = 0; j < temp_len; j++)
                {
                    a += relation[i][temp[j]];
                }
                if (dic[a] == 1)
                {
                    check = false;
                    break;
                }
                dic[a] = 1;
            }
            if (check)
            {
                result.push_back(temp);
            }
        } while (next_permutation(idx.begin(), idx.end()));
        count++;
    }

    // 최소성 체크
    vector<vector<int>> answer;
    for (auto uniqueness : result)
    {
        bool check2 = true;
        for (auto minimality : answer)
        {
            int cnt = 0;
            for (int a : minimality)
            {
                if (find(uniqueness.begin(), uniqueness.end(), a) != uniqueness.end())
                    cnt++;
            }
            if (cnt == minimality.size())
            {
                check2 = false;
                break;
            }
        }
        if (check2)
            answer.push_back(uniqueness);
    }

    return answer.size();
}