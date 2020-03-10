#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solution(vector<int> money) {
    int DP1[2] = {money[0], money[0]};  // 1st 반드시 포함
    int DP2[2] = {money[1], money[1]};  // 2nd 반드시 포함
    int DP3[2] = {money[2], money[2]};  // 3rd 반드시 포함
    int len = money.size();
    if(len == 3){
        return *max_element(money.begin(), money.end());
    }
    for(int i = 0; i < len - 3; i++){
        if(DP1[0] + money[i+2] > DP1[1]){
            DP1[0] += money[i+2];
            swap(DP1[0], DP1[1]); 
        }
        else{
            DP1[0] = DP1[1];
        }
    }
    for(int i = 1; i < len - 2; i++){
        if(DP2[0] + money[i+2] > DP2[1]){
            DP2[0] += money[i+2];
            swap(DP2[0], DP2[1]);
        }
        else{
            DP2[0] = DP2[1];
        }
    }
    for(int i = 2; i < len - 2; i++){
        if(DP3[0] + money[i+2] > DP3[1]){
            DP3[0] += money[i+2];
            swap(DP3[0], DP3[1]);
        }
        else{
            DP3[0] = DP3[1];
        }
    }
    vector<int> answer;
    answer.push_back(DP1[1]);
    answer.push_back(DP2[1]);
    answer.push_back(DP3[1]);
    return *max_element(answer.begin(), answer.end());
}
