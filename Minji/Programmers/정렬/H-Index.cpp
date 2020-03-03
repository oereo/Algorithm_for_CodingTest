#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end());
    int len = citations.size();
    int start = 0;
    int end = len;
    while(start < end) {
        int mid = (start + end + 1) / 2;
        if(citations[len-mid] >= mid)
            start = mid;
        else
            end = mid - 1;
    }
    return end;
}
