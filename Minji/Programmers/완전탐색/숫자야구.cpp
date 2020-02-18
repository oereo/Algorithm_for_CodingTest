#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check(string A, string B, int s, int b){
    int strike = 0;
    int ball = 0;
    if(A[0] == B[0]) strike++;
    if(A[1] == B[1]) strike++;
    if(A[2] == B[2]) strike++;
    if(A[0] == B[1] || A[0] == B[2]) ball++;
    if(A[1] == B[0] || A[1] == B[2]) ball++;
    if(A[2] == B[0] || A[2] == B[1]) ball++;
    if(strike == s && ball == b)
        return true;
    return false;
}
int solution(vector<vector<int>> baseball) {
    vector<int> ans;
    for(int a = 1; a <= 9; a++) {   // 첫 질문
        for(int b = 1; b <= 9; b++) {
            for(int c = 1; c <= 9; c++) {
                if(a == b || a == c || b == c)
                    continue;
                string A = to_string(baseball[0][0]);
                int temp = a*100 + b*10 + c;
                string B = to_string(temp);
                if(check(A,B,baseball[0][1],baseball[0][2]))
                    ans.push_back(temp);
            }
        }
    }
    
    int len = baseball.size();
    vector<int>::iterator iter;
    for(int i = 1; i < len; i++){   // 두번째 질문부터
        for(iter = ans.begin(); iter != ans.end(); iter++){
            string A = to_string(baseball[i][0]);
            string B = to_string(*iter);
            if(!check(A,B,baseball[i][1],baseball[i][2])){
                ans.erase(iter);
                iter--;
            }
        }
        if(ans.size() == 1)
            return 1;
    }
    int answer = ans.size();
    return answer;
}
