#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string s)
{
    int sIdx = 0;
    bool check = false;
    while (!check)
    {
        if (s[sIdx] >= 'a' && s[sIdx] <= 'z')
        {
            s[sIdx] -= 32;
        }
        int nIdx = s.find(" ", sIdx);
        if (nIdx == std::string::npos)
        {
            nIdx = s.size();
            check = true;
        }
        for (int i = sIdx + 1; i < nIdx; i++)
        {
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                s[i] += 32;
            }
        }
        sIdx = nIdx + 1;
    }
    return s;
}