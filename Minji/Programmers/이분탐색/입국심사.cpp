#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(),times.end());
    long long start = 0;
    long long end = (long long)times.front() * n;    // ÀÚ·áÇü
    long long mid = 0;
    long long len = times.size();
    while(start < end){
        mid = (start + end) / 2;
        long long total = 0;
        for(int i = 0; i < len; i++){
            total += mid/times[i];
        }
        if(total < n)
            start = mid + 1;
        else
            end = mid;
    }
    
    long long answer = end;
    return answer;
}
