#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int red) {
    vector<pair<int,int>> temp;
    for(int i = 1 ; i <= red ; i++){
        if(red % i == 0){
            if(red/i < i)
                break;
            temp.push_back({red/i,i});
        }
    }
    
    vector<int> answer;
    for(auto i : temp){
        if((i.first + i.second +2)*2 == brown){
            answer.push_back(i.first + 2);
            answer.push_back(i.second + 2);
            break;
        }
    }
    
    return answer;
}
