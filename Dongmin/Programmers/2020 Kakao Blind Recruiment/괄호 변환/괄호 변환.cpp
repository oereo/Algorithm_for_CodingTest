#include <string>
#include <vector>

using namespace std;

bool isRight(string s) {
    // 입력 문자열은 균형잡힌 문자열이라 가정한다.
    int numLeft = 1, numRight = 0;
    if (s.front() != '(') return false;
    for (int i = 1; i < s.size(); i++) {
        if (numLeft < numRight) {
            return false;
        }
        if (s.at(i) == '(') {
            numLeft++;
        }
        else {
            numRight++;
        }
    }
    return true;
}

bool isBalanced(string s) {
    int numLeft = 0, numRight = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '(') {
            numLeft++;
        }
        else {
            numRight++;
        }
    }
    return (numLeft == numRight);
}

void divideBalanceStrings(string origin, string& u, string& v) {
    // 균형잡힌 문자열을 뽑아내면 나머지는 무조건 균형잡힌 문자열이다.
    for (int len = 1; len <= origin.size(); len++) {
        string frontStr = origin.substr(0, len);
        if (isBalanced(frontStr)) {
            u.assign(frontStr);
            v.assign(origin.substr(len));
            return;
        }
    }
}

void removeFirstLast(string& s) {
    s = s.substr(1);
    s.pop_back();
}

string reverseParenthesis(string s) {
    string ret = "";
    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == '(') {
            ret += ')';
        }
        else {
            ret += '(';
        }
    }
    return ret;
}

string solution(string p) {
    string u, v;
    string answer = "";
    if (p == "") {
        return "";
    }

    divideBalanceStrings(p, u, v);
    if (isRight(u)) {
        u += solution(v);
        answer += u;
    }
    else {
        answer += '(';
        answer += solution(v);
        answer += ')';
        removeFirstLast(u);
        answer += reverseParenthesis(u);
    }
    return answer;
}