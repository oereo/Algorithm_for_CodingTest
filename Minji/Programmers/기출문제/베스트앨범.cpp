#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(const vector<int> &A, const vector<int> &B)
{
    if (A[0] > B[0])
        return true;
    else if (A[0] == B[0])
    {
        if (A[1] > B[1])
            return true;
        else if (A[1] == B[1])
        {
            return A[2] < B[2];
        }
    }
    return false;
}

vector<int> solution(vector<string> genres, vector<int> plays)
{
    // 장르별 총 재생 수 구하기
    int len = plays.size();
    map<string, int> dic;
    for (int i = 0; i < len; i++)
    {
        dic[genres[i]] += plays[i];
    }
    // 장르별 총 재생 수, 노래 재생 수, 노래 인덱스 저장
    vector<vector<int>> result(len, vector<int>(3));
    for (int i = 0; i < len; i++)
    {
        result[i][0] = dic[genres[i]];
        result[i][1] = plays[i];
        result[i][2] = i;
    }

    // 장르별로 최대 2개 저장
    sort(result.begin(), result.end(), cmp);
    vector<int> answer;
    int count = 0;
    int now = result[0][0];
    for (int i = 0; i < len; i++)
    {
        if (now != result[i][0])
        {
            count = 0;
            now = result[i][0];
        }
        if (count == 2)
            continue;
        answer.push_back(result[i][2]);
        count++;
    }
    return answer;
}