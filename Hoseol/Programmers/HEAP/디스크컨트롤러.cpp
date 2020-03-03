#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
bool compare( vector<int> a, vector<int> b){
  if(a[1] == b[1])
    return a[0] < b[0];
  else return a[1] < b[1];
}
int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int time_spend = 0; int time = 0;
    vector<vector<int>> disks;
    for (int i = 0; i < jobs.size(); i++) 
    {
        vector<int> temp;
        temp.push_back(jobs[i][0]);
        temp.push_back(jobs[i][1]);
        disks.push_back(temp);
    }
    sort(disks.begin(), disks.end(),compare);
    for(int i=0;i<disks.size();i++)
    {
        cout<<disks[i][0]<<","<<disks[i][1]<<endl;
    }
    while (!disks.empty()) {
        for (int i = 0; i < disks.size(); i++) {
            if (disks[i][0] <= time_spend) {
                time_spend += disks[i][1];
                time += time_spend - disks[i][0];
                disks.erase(disks.begin() + i);
                break;
            } 
            if (i == disks.size()-1) time_spend++;    
        }
        
    }
    answer = time / jobs.size();
    return answer;
}