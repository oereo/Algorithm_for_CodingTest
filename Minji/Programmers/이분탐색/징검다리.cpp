#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int len = rocks.size();
    if(len == n)
        return distance;
    
    sort(rocks.begin(), rocks.end());
    vector<int> gap;
    int start = 0;
    for(int i = 0; i < len; i++){
        gap.push_back(rocks[i] - start);
        start = rocks[i];
    }
    gap.push_back(distance - start);
    
    int low = 1;
    int high = distance;
    while(low < high){
        int mid = (low + high + 1) / 2;
        int count = 0;
        int prev = 0;
        for(int i = 0; i < len + 1; i++){
            if(mid <= gap[i] + prev){
                prev = 0;
            }
            else{
                count++;
                prev += gap[i];
            }
        }
        if(count > n)
            high = mid - 1;
        else
            low = mid;
    }
    return low;
}
