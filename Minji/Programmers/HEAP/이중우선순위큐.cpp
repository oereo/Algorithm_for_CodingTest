#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    int len = operations.size();
    vector<int> v;
    for(int i = 0; i < len; i++) {
        if(operations[i][0] == 'I'){    // »ðÀÔ
            v.push_back(stoi(operations[i].substr(2)));
        }
        else if(operations[i][2] == '-') {  // ÃÖ¼Ú°ª »èÁ¦
            if(v.empty())
                continue;
            v.erase(min_element(v.begin(), v.end()));
        }
        else{   // ÃÖ´ñ°ª »èÁ¦
            if(v.empty())
                continue;
            v.erase(max_element(v.begin(), v.end()));
        }
    }
    if(v.empty()){
        v.push_back(0);
        v.push_back(0);
        return v;
    }
    sort(v.begin(), v.end());
    vector<int> answer;
    answer.push_back(v.back());
    answer.push_back(v.front());
    return answer;
}
