#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
map<int,int> M;
long long dp[21]={1,1,};
vector<int> people;
long long ans;
vector<int>answer;
vector<int> solution(int n, long long k) {
    for(int i=1;i<=n;i++)
    {
        dp[i]=i*dp[i-1];
        people.push_back(i);
    }
    long long key=n-1;
    long long number=-1;
    long long idx=-1;
    while(key>0)
    {
        if(k%dp[key]!=0)
        {number=k/dp[key]; idx=dp[key]*number;}
        else
        {number=k/dp[key]-1; idx=dp[key]*number;}
        answer.push_back(people[number]);
        people.erase(people.begin()+number);
        k-=idx;
        key--;
    }
    answer.push_back(people[0]);
    return answer;
}