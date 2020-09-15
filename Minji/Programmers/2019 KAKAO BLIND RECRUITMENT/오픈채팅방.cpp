#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
    map<string, string> dic;  // ID, 닉네임
    vector<string> result_id; // ID
    vector<string> result_op; // 옵션
    int len = record.size();
    for (int i = 0; i < len; i++)
    {
        // 옵션
        int start = 0;
        int end = record[i].find(" ", start);
        string option = record[i].substr(start, end);

        // ID
        start = end + 1;
        end = record[i].find(" ", start);
        string id = record[i].substr(start, end - start);

        // 닉네임
        string nick = record[i].substr(end + 1);

        if (option == "Enter")
        {
            dic[id] = nick;
            result_id.push_back(id);
            result_op.push_back("님이 들어왔습니다.");
        }
        else if (option == "Leave")
        {
            result_id.push_back(id);
            result_op.push_back("님이 나갔습니다.");
        }
        else
        {
            dic[id] = nick;
        }
    }
    int result_len = result_id.size();
    vector<string> answer(result_len);
    for (int i = 0; i < result_len; i++)
    {
        answer[i] = dic[result_id[i]] + result_op[i];
    }
    return answer;
}