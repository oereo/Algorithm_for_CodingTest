// 투 포인터
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> stones, int k) {
    int answer = 0;
    int n = stones.size();
    map<int,int,greater<int> > windowEl;

    int max = 0;
    for(int i=0; i<k; i++) {
        int num = stones[i];
        if(num>max) max = num;
        if(!windowEl.count(num)) windowEl[num] = 1;
        else windowEl[num] += 1;
    }

    int min = max;
    for(int i=1; i<n-k+1; i++) {
        int leftRm = stones[i-1], rightPl = stones[k+i-1];
        windowEl[leftRm] -= 1;
        if(!windowEl.count(rightPl)) {
            windowEl[rightPl] = 1;
        }
        else {
            windowEl[rightPl] += 1;
        }

        if(windowEl[leftRm] == 0) windowEl.erase(leftRm);

        if(rightPl > max) max = rightPl;
        else {
            if(!windowEl.count(max)) {
                auto it = windowEl.lower_bound(max);
                max = (*it).first;
            }
        }

        if(min > max) min = max;
    }
    answer = min;
    return answer;
}