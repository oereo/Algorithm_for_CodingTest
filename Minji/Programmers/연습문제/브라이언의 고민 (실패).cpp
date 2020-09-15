// Test Case만 통과

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string answer;
vector<char> lower;
int len, idx;

int remove(string sentence)
{
    while (1)
    {
        if (sentence[idx + 1] >= 'a' && sentence[idx + 1] <= 'z') // ex) AacacaA
            return 2;
        answer += sentence[idx + 1];
        idx += 2;
        if (idx == len)
            return 1; // 답 리턴
        if (idx > len)
            return 2; // invalid ex) AaAaAa
        if (sentence[idx] != lower.back())
            break;
    }
    return 0;
}

string solution(string sentence)
{
    len = sentence.size();
    idx = 0;
    answer = "";
    while (1)
    {
        // 규칙 1
        if (sentence[idx] >= 'A' && sentence[idx] <= 'Z')
        {
            answer += sentence[idx];
            idx++;
            if (sentence[idx] >= 'a' && sentence[idx] <= 'z')
            {
                if (find(lower.begin(), lower.end(), sentence[idx]) != lower.end())
                    return "invalid";
                if (sentence[idx] != sentence[idx + 2] && sentence.find(sentence[idx], idx + 1) != string::npos)
                {
                    answer += ' ';
                    continue;
                }
                lower.push_back(sentence[idx]);
                int check = remove(sentence);
                if (check == 1)
                    return answer;
                else if (check == 2)
                    return "invalid";
            }
        }
        // 규칙 2 & 규칙 1+2
        else
        {
            if (find(lower.begin(), lower.end(), sentence[idx]) != lower.end())
                return "invalid";
            lower.push_back(sentence[idx]);
            int idx2 = sentence.find(lower.back(), idx + 1);
            if (sentence[idx] != sentence[idx + 2] && sentence[idx + 2] >= 'a' && sentence[idx + 2] <= 'z')
            { // 규칙 1+2
                idx++;
                answer += sentence[idx];
                idx++;
                if (find(lower.begin(), lower.end(), sentence[idx]) != lower.end())
                    return "invalid";
                lower.push_back(sentence[idx]);
                if (remove(sentence))
                    return answer;
            }
            else
            { // 규칙 2
                answer += sentence.substr(idx + 1, idx2 - idx - 1);
                idx = idx2 + 1;
            }
        }
        if (idx == len)
            break;
        answer += ' ';
    }
    return answer;
}