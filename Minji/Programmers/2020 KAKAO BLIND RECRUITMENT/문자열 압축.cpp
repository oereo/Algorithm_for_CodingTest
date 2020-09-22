#include <string>
using namespace std;

int solution(string s)
{
    int n = s.size();
    int answer = n;
    int sidx, len, cnt, num_len;
    for (int i = 1; i <= n / 2; i++)
    {
        sidx = 0, len = 0, cnt = 1;
        string start = s.substr(sidx, i);
        while (1)
        {
            if (cnt < 10)
                num_len = 1;
            else if (cnt >= 10 && cnt < 100)
                num_len = 2;
            else if (cnt >= 100 && cnt < 1000)
                num_len = 3;
            else if (cnt == 1000)
                num_len = 4;

            if (sidx + i >= n)
            {
                if (cnt == 1)
                    len += n - sidx;
                else
                    len += num_len + i;
                break;
            }

            sidx += i;
            string next = s.substr(sidx, i);

            if (next == start)
                cnt++;
            else
            {
                if (cnt == 1)
                    len += i;
                else
                    len += num_len + i;
                start = next;
                cnt = 1;
            }
        }

        if (answer > len)
            answer = len;
    }
    return answer;
}