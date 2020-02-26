#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(),people.end());
    int len=people.size();
    int cnt=0;
    int pointF=0;
    int pointB=len-1;
    while(len>0)
    {
        int weight=0;
        if(people[pointB]+weight<=limit)
        {
            weight+=people[pointB];
            len--;
            pointB--;
        }
        if(len>0)
        {
            if(people[pointF]+weight<=limit)
            {
                weight+=people[pointF];
                pointF++;        
                len--;
            }
        }
        cnt++;
    }
    
    return cnt;
}