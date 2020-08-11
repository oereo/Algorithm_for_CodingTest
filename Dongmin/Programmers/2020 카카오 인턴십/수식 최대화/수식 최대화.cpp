#include <string>
#include <algorithm>
#include <vector>

using namespace std;
vector<long long> nums, ntmp;
vector<char> ops, otmp;

long long calOp(char op, long long n1, long long n2) {
    if(op=='+') {
        return n1+n2;
    }
    else if(op=='*') {
        return n1*n2;
    }
    else {
        return n1-n2;
    }
}

long long calExp(string op) {                                                 
    ntmp = nums;
    otmp = ops;
    
    for(int i=0; i<3; i++){
        size_t sz = otmp.size();
        for(int j=0; j<sz; j++) {
            if(op[i] == otmp[j]) {
                long long addnum = calOp(otmp[j], ntmp[j], ntmp[j+1]);
                otmp.erase(otmp.begin()+j);
                ntmp.erase(ntmp.begin()+j);
                ntmp.erase(ntmp.begin()+j);
                ntmp.insert(ntmp.begin()+j, addnum);
                j--;
                sz--;
            }
        }
    }
    
    return abs(ntmp[0]);
}

long long solution(string expression) {
    long long answer = 0;

    string num="";
    for(auto ch:expression) {
        if(isdigit(ch)){
            num+=ch;
        }
        else {
            nums.push_back(atoi(num.c_str()));
            ops.push_back(ch);
            num="";
        }
    }
    nums.push_back(atoi(num.c_str()));

    vector<long long> results;
    results.push_back(calExp("+-*"));
    results.push_back(calExp("+*-"));
    results.push_back(calExp("-+*"));
    results.push_back(calExp("-*+"));
    results.push_back(calExp("*+-"));
    results.push_back(calExp("*-+"));
    answer = *max_element(results.begin(), results.end());

    return answer;
}

int main() {
    printf("%lld\n", solution("100-200*300-500+20"));
    return 0;
}