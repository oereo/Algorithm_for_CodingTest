#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string change(int time)
{
    int hours = time / 60;
    int minutes = time % 60;
    string result = "";
    if (hours < 10)
        result += "0";
    result += to_string(hours);
    result += ":";
    if (minutes < 10)
        result += "0";
    result += to_string(minutes);
    return result;
}

string solution(int n, int t, int m, vector<string> timetable)
{
    // 시간 int로 변환하기
    int len = timetable.size();
    int hours, minutes, time;
    vector<int> timetable2;
    sort(timetable.begin(), timetable.end());
    for (int i = 0; i < len; i++)
    {
        if (timetable[i] > "18:00")
            break;
        hours = stoi(timetable[i].substr(0, 2));
        minutes = stoi(timetable[i].substr(3));
        time = hours * 60 + minutes;
        timetable2.push_back(time);
    }

    int len2 = timetable2.size();
    int last_bus = 540 + t * (n - 1); // 마지막 버스 시간
    int count = 0;
    int now = 540;
    string answer;
    for (int i = 0; i < len2; i++)
    {
        if (timetable2[i] > now)
        {
            now += t;
            count = 0;
            i--;
            continue;
        }

        count++;
        if (count == m)
        {
            if (now == last_bus)
            {
                answer = change(timetable2[i] - 1);
                return answer;
            }
            now += t;
            count = 0;  
        }
    }
    answer = change(last_bus);
    return answer;
}