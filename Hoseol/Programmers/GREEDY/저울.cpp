#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;

    sort(weight.begin(), weight.end());
    
    answer = 1;
    if(answer==weight[0]){
    for (int i = 1; i < weight.size(); i++) {
        if (answer+1 < weight[i]) break;
        else answer += weight[i];
    }
    }
    return answer+1;
}