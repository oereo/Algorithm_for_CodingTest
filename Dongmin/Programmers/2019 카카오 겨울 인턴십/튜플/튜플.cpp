#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef struct idxSize {
    int idx;
    int size;
} idxSize;
struct cmp{
    bool operator()(idxSize a, idxSize b) {
        return a.size > b.size;
    }
};
priority_queue<idxSize, vector<idxSize>, cmp> pq;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int> > setArr;
    vector<int> subArr;
    int idx=0;
    int buf[6];
    int digit=0, num;

    for(int i=1; i<s.length()-1; i++) {
        if(s[i]=='{') {
            i += 1;
            buf[digit++] = s[i] - '0';
        }
        else if(s[i] == ',') {
            num = 0;
            for(int dig=pow(10,digit-1), j=0; j<digit; j++, dig/=10) {
                num += buf[j] * dig;
            }
            subArr.push_back(num);
            digit=0;
        }
        else if(s[i] == '}') {
            i += 1;
            num = 0;
            for(int dig=pow(10,digit-1), j=0; j<digit; j++, dig/=10) {
                num += buf[j] * dig;
            }
            subArr.push_back(num);
            sort(subArr.begin(), subArr.end());
            setArr.push_back(subArr);
            
            int size = subArr.size();
            pq.push(idxSize{idx++, size});
            subArr.clear();
            digit=0;
        }
        else {
            buf[digit++] = s[i] - '0';
        }
    }

    vector<int> prev;
    while(!pq.empty()) {
        idxSize top = pq.top();
        pq.pop();
        if(top.size == 1) {
            prev = setArr[top.idx];
            answer.push_back(prev[0]);
        }
        else {
            for(int i=0; i<setArr[top.idx].size(); i++) {
                if(setArr[top.idx][i] != prev[i]) {
                    answer.push_back(setArr[top.idx][i]);
                    break;
                }
            }
            prev = setArr[top.idx];
        }
    }
    return answer;
}