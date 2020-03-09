#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());
    int len = routes.size();
    int answer = 1;
    int start = routes[0][0];
    int end = routes[0][1];
    for(int i = 1; i < len; i++) {
        if(routes[i][0]>= start && routes[i][0] <= end){
            if(end > routes[i][1])
                end = routes[i][1];
        }
        else{
            answer++;
            start = routes[i][0];
            end = routes[i][1];
        }
    }
    return answer;
}