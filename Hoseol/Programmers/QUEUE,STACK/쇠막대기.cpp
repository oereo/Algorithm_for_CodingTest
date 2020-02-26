#include <string>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
int C;
int countF = 0;
int solution(string arrangement) {
    int temp = arrangement.length();
    for (int i = 0; i < temp; i++)
    {
        if (arrangement[i] == 0) { break; }

        else if (arrangement[i] == '(')
        {
            countF++;
            C++;
        }
        else if (arrangement[i] == ')'&&i >= 1)
        {
            countF--;
            if (arrangement[i - 1] == '(')
            {
                C += countF-1;
            }   
        }
    }



    int answer = C;
    return answer;
}