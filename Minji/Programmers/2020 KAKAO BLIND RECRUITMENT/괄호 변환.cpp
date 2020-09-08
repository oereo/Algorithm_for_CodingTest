#include <string>

using namespace std;

string answer = "";

string change(string s, int len){
    string temp = "";
    for (int i = 1; i < len - 1; i++){
        if (s[i] == '(') temp += ')';
        else temp += '(';
    }
    return temp;
}

string sparate(string s, int len) {
    if (len == 0) return "";
    int cnt = 0;
    string u, v;
    string result = "";
    bool check = true;
    for (int i = 0; i < len; i++) {
        if (s[i] == '(') cnt++;
        else cnt--;

        if (cnt < 0) check = false;
        if (cnt == 0) {
            u = s.substr(0, i + 1);
            v = s.substr(i + 1, len - i - 1);
            if (check) { // 올바른 괄호 문자열
                result += u;
                result += sparate(v, len - i - 1);
                return result;
            } else { // 균형잡힌 괄호 문자열
                result += '(';
                result += sparate(v, len - i - 1);
                result += ')';
                result += change(u, i + 1);
                return result;
            }
        }
    }
}

string solution(string p){
    int len = p.size();
    return sparate(p, len);
}